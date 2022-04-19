// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[0] = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != -1) {
                for (int j = 1; j <= nums[i]; ++j) {
                    if (j + i < nums.size()) {
                        if (dp[i + j] == -1 || dp[i + j] > dp[i] + 1) {
                            dp[i + j] = dp[i] + 1; 
                        } 
                    }
                }
            }
        }
        return dp.back(); 
    }
};