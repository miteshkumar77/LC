// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> ct(26, 0);
        for (char c : str) ++ct[c-'a'];
        string ans;
        for (char c : order) {
            ans += string(ct[c-'a'], c);
            ct[c-'a'] = 0;
        }
        for (int i = 0; i < 26; ++i) {
            ans += string(ct[i], (i + 'a'));
        }
        return ans;
        
    }
};