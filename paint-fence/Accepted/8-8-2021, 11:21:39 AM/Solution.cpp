// https://leetcode.com/problems/paint-fence

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 1;
        vector<array<int, 2>> dp(n, {1, 0});
        int sum = k;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (j == 0) {
                    dp[i][j] = sum - (dp[i-1][0] + dp[i-1][1]);
                } else {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
            sum = k * (dp[i][0] + dp[i][1]);
        }
        return sum;
    }
};