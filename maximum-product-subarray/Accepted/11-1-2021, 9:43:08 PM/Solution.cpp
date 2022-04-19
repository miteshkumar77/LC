// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int gmax = nums[0];
        int gmin = nums[0];
        int lmax = nums[0];
        int lmin = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) {
                swap(lmax, lmin);
            }
            lmax = max(lmax * nums[i], nums[i]);
            lmin = min(lmin * nums[i], nums[i]);
            gmax = max(gmax, lmax);
            gmin = min(gmin, lmin);
        }
        return gmax;
    }
};