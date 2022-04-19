// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k + 1;
        nth_element(nums.begin(), nums.begin() + k, nums.end());
        return nums[k - 1];
    }
};