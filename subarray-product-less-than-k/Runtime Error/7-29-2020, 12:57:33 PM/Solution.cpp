// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(); 
        int j = 0; 
        int current_prod = 1; 
        int ans = 0; 
        for (int i = 0; i < n; ++i) {
            current_prod *= nums[i];
            
            while(current_prod >= k) {
                current_prod /= nums[j++]; 
            }
            ans += i - j + 1; 
        }
        return ans; 
    }
};