// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i-1;
        }
        for (int i = 4; i <= n; ++i) {
            for (int j = 2; j + 1 < i; ++j) {
                dp[i] = max(dp[i], dp[i-j] * dp[j]);
            }
        }
        return dp[n];
    }
};