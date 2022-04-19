// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1; 
        }
        vector<int> dp(nums.size(), 1);
        int max = 0; 
        for (int i = 1; i < nums.size(); ++i) {
        
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1; 
                }
            }
            if (dp[i] > max) {
                max = dp[i]; 
            }
        }
        
        return max; 
        
        
        
        
    }
    
    
};