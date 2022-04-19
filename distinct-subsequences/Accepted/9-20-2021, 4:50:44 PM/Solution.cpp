// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        using ll = unsigned long long;
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
        /*
            dp[i][j]: number of subsequences of s[0:i]
            that equal t[0:j]
        */
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i < j) continue;
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
                dp[i][j] += dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};