// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans = nums[0]; 
        int imax = nums[0]; 
        for (int i = 1; i < nums.size(); ++i) {
            imax = max(nums[i], imax + nums[i]); 
            ans = max(ans, imax); 
        }
        return ans; 
    }
};