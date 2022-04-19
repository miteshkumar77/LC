// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<bool>> ct(26, vector<bool>(26, 0));
        vector<int> earliest(26, (int)1e9);
        vector<int> latest(26, (int)-1e9);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (earliest[s[i]-'a'] < latest[j]) {
                    ct[s[i]-'a'][j] = true;
                }
            }
            earliest[s[i]-'a'] = min(earliest[s[i]-'a'], i);
            latest[s[i]-'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans += (int)ct[i][j];
            }
        }
        return ans;
    }
};