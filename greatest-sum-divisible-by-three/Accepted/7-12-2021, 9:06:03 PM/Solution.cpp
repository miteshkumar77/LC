// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3, INT_MIN));
        dp[0][0] = 0;
        int p;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                p = (j + 3 - nums[i-1]%3)%3;  
                dp[i][j] = max(dp[i-1][j], dp[i-1][p] + nums[i-1]);
                // cout << dp[i][j] << ' ';
            }
            // cout << endl;
        }
        return max(0, dp[n][0]);
    }
};