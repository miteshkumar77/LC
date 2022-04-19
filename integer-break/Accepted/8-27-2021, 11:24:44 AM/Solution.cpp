// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i-1;
        }
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                // cout << i << ' ' << j << ' ' << i-j << ' ' << dp[i-j] * dp[j] << ":::";
                dp[i] = max(dp[i], max(i-j, dp[i-j]) * max(j, dp[j]));
            }
        }
        return dp[n];
    }
};