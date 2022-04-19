// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(); int m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = p[i-1] == '*' && dp[0][i-2];
        }
        for (int s_p = 1; s_p <= n; ++s_p) {
            for (int p_p = 1; p_p <= m; ++p_p) {
                if (p[p_p-1] == '.' || p[p_p-1] == s[s_p-1]) {
                    dp[s_p][p_p] = dp[s_p-1][p_p-1];
                } else if (p[p_p-1] == '*') {
                    bool can_skip = dp[s_p][p_p-2];
                    bool prev_matches = p[p_p-2] == s[s_p-1] || p[p_p-2] == '.';
                    bool first_match = prev_matches && dp[s_p-1][p_p-1];
                    bool repeated_match = prev_matches && dp[s_p-1][p_p];
                    dp[s_p][p_p] = can_skip || first_match || repeated_match;
                }
            }
        }
        return dp[n][m];
    }
};