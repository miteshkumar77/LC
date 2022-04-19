// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(); int n = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
        /*
            dp[i][j]: can s[0:i] be matched with p[0:j]
        */
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = p[i-1] == '*' && dp[i-1][0];
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[i-1] == '*') {
                    dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                } else if (p[i-1] == '?' || (p[i-1] == s[j-1])) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        
        return dp[n][m];
    }
};