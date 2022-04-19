// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; int r = nums.size()-1;
        int mid;
        while(l < r) {
            mid = l + (r - l)/2;
            if (nums[mid] > nums[l]) {
                l = mid + 1;
            } else {
                // nums[mid] <= nums[l]
                // min is either mid or to its right
                r = mid;
            }
        }
        return nums[r];
    }
};