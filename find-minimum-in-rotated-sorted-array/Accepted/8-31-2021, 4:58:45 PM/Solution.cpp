// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0; int r = n-1; int mid;
        while(l < r) {
            mid = l + (r - l)/2;
            if (nums[mid] <= nums[n-1])
                r = mid;
            else
                l = mid+1;
        }
        return nums[r];
    }
};