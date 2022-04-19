// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        int leftbal, rightbal;
        for (int i = 1; i <=n; ++i) {
            for (int j = i; j >= 1; --j) {
                for (int k = j; k <= i; ++k) {
                    rightbal = i == n ? 1 : nums[i];
                    leftbal  = j == 1 ? 1 : nums[j - 2];
                    dp[i][j] = max(dp[i][j], rightbal * nums[k - 1] * leftbal + dp[k - 1][j] + dp[i][k + 1]);
                }
            }
        }
        
        return dp[n][1];
    }
};