// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 2>> dp(n, {1, 1});
        
        // dp[i][0]: end is a valley
        // dp[i][1]: end is a peak
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                dp[i][0] = max(dp[i - 1][1] + 1, dp[i - 1][0]);
                dp[i][1] = dp[i - 1][1];
            } else if (nums[i] > nums[i - 1]) {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][1]);
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};