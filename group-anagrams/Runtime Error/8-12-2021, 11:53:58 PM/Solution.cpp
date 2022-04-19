// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<string>> g;
        array<long long, 26> p{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        for (int i = 0; i < strs.size(); ++i) {
            long long prod = 1;
            for (char c : strs[i]) {
                prod *= p[c-'a'];
            }
            g[prod].push_back(strs[i]);
        }
        vector<vector<string>> v;
        v.reserve(g.size());
        for (const auto& p : g) v.push_back(p.second);
        return v;
    }
};