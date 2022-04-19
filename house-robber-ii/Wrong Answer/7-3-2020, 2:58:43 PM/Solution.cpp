// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size()); 
        if (nums.size() == 0) {
            return 0; 
        }
        
        if (nums.size() == 1) {
            return nums[0]; 
        }
        dp1[0] = 0; 
        dp1[1] = nums[1]; 
        
        for (int i = 2; i < nums.size(); ++i) {
            dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]); 
        }
        int a1 = dp1.back(); 
        
        dp1[0] = nums[0]; 
        
        for (int i = 2; i < nums.size() - 1; ++i) {
            dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]); 
        }
        int a2 = dp1[dp1.size() - 2]; 
        return max(a1, a2); 
    }
    
    
    
    
    
    
};