// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < min(i + 1, n); ++j) {
                dp[i] = max(dp[i], dp[i-j] * j);
            }
        }
        return dp[n];
    }
};