// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1;
        int j = 0; 
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while(j <= i && prod >= k) {
                prod /= nums[j++];
            }
            if (j <= i) {
                ans += i - j + 1;
            }
        }
        return ans; 
    }
};