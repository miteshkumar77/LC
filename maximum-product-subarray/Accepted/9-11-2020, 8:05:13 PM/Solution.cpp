// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int g_largest = nums[0]; 
        int c_largest = nums[0]; 
        int c_smallest = nums[0]; 
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(c_largest, c_smallest); 
            }
            c_largest = max(nums[i], c_largest * nums[i]); 
            c_smallest = min(nums[i], c_smallest * nums[i]); 
            g_largest = max(g_largest, c_largest); 
        }
        return g_largest; 
    }
};