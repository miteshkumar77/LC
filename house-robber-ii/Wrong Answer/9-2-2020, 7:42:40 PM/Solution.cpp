// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0; 
        }
        vector<int> dp1(nums.size()); 
        dp1[0] = 0; 
        dp1[1] = nums[1]; 
        for (int i = 2; i < nums.size(); ++i) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]); 
        }
        
        vector<int> dp2(nums.size()); 
        dp2[0] = nums[0]; 
        dp2[1] = max(nums[0], nums[1]); 
        for (int i = 2; i < nums.size() - 1; ++i) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]); 
        }
        
        return max(dp1.back(), dp2[dp2.size() - 2]); 
    }
    
    
    
    
    
    
};