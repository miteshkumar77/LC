// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0; 
        int j = 0; 
        unsigned long long int running_product = 1; 
        for (int i = 0; i < nums.size(); ++i) {
            running_product *= nums[i]; 
            while(running_product >= k && j <= i) {
                running_product/= nums[j++]; 
            }
            ans += (i - j + 1); 
        }
        return ans; 
    }
};