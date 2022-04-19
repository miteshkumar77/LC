// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(); int m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = p[i-1] == '*' && dp[0][i-2];
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    bool can_empty = dp[i][j-2];
                    bool can_prev_match = s[i-1] == p[j-2] || p[j-2] == '.';
                    bool can_be_first = can_prev_match && dp[i-1][j-1];
                    bool can_be_repeat = can_prev_match && dp[i-1][j];
                    dp[i][j] = can_empty || can_be_first || can_be_repeat;
                }
            }
        }
        return dp[n][m];
    }
};