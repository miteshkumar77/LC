// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0; 
        for (int num : nums) {
            total_sum += num; 
        }
        
        if (total_sum % 2 != 0) {
            return false; 
        }
        
        total_sum /= 2; 
        
        vector<vector<bool> > dp(nums.size() + 1, vector<bool>(total_sum + 1, false)); 
        for (int i = 0; i <= nums.size(); ++i) {
            dp[i][0] = true; 
        }
        
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= total_sum; ++j) {
                dp[i][j] = dp[i - 1][j] || (j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]]); 
            }
        }
        
        
        
        return dp.back().back(); 
        
        
    }
    
    
};