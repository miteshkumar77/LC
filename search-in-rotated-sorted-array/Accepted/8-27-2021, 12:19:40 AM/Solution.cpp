// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0; int r = n-1; int mid;
        int br = 0;
        while(nums[l] > nums[r]) {
            mid = l + (r - l)/2;
            if (nums[mid] < nums[r]) {
                br = mid;
                r = mid - 1;
            } else {
                l = mid + 1;        
                br = l;
            }
        }
        l = 0; r = n-1;
        if (nums[br] <= target && nums[n-1] >= target) {
            l = br;
        } else {
            r = br - 1;
        }
        while(l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] == target) {
                return mid;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};