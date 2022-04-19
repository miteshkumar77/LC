// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        vector<pair<char,int>> equivalent;
        for (char c : s) {
            if (equivalent.size() != 0 && equivalent.back().first == c) {
                ++equivalent.back().second;
            } else {
                equivalent.push_back({c, 1});
            }
            if (equivalent.back().second == k) {
                equivalent.pop_back();
            }
        }
        string ans;
        for (auto p : equivalent) {
            ans += string(p.second, p.first);
        }
        
        return ans;
    }
};