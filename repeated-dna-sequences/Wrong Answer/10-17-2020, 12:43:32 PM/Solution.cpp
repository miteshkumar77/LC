// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> ct;
        for (int i = 0; i + 10 < s.length(); ++i) {
            ++ct[s.substr(i, 10)];
        }
        vector<string> ans;
        for (auto p : ct) {
            if (p.second > 1) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};