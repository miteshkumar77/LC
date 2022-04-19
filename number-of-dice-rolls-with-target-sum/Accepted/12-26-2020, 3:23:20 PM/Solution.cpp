// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        // dp[r][t] = number of ways to get a target number on 
        // roll r. 
        int M = 1e9 + 7;
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        
        for (int r = 1; r <= d; ++r) {
            for (int t = 1; t <= target; ++t) {
                dp[r][t] = (dp[r - 1][t - 1] + dp[r][t - 1]) % M;
                if (t > f) {
                    dp[r][t] = (dp[r][t] + M - dp[r - 1][t - f - 1]) % M;
                }
            }
        }
        
        return dp[d][target];
    }
};