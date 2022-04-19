// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

class Solution {
public:
    typedef signed long long int slli;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        vector<vector<slli>> dp(m + 1, vector<slli>(m + 1, 0));
        /*
            dp[l][r]: max score if we've taken l from left, and r from right
        */
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = dp[0][i-1] + (slli)multipliers[i-1] * (slli)nums[n-i];
            dp[i][0] = dp[i-1][0] + (slli)multipliers[i-1] * (slli)nums[i-1];
        }
        slli ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j+i <= m; ++j) {
                dp[i][j] = max(dp[i-1][j] + (slli)multipliers[i+j-1] * (slli)nums[i-1], dp[i][j-1] + (slli)multipliers[i+j-1] * (slli)nums[n-j]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};