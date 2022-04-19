// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[0]; 
        
        int ans = nums[0]; 
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(smallest, largest); 
            }
            
            largest = max(largest * nums[i], nums[i]); 
            smallest = min(smallest * nums[i], nums[i]); 
            ans = max(ans, largest); 
        }
        return ans; 
    }
};