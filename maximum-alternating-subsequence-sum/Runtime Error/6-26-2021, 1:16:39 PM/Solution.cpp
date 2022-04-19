// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<array<int,2>> dp(n + 1, {0,0});
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = max(dp[i-1][0], nums[i-1] + dp[i-1][1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - nums[i-1]);
        }
        return max(dp[n][0], dp[n][1]);
        /*
            dp[i][0] : ending in an even
            dp[i][1] : ending in an odd
        */
    }
};