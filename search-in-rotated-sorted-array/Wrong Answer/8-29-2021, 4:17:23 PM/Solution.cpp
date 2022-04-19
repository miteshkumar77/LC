// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0; int r = n-1;
        int mid; int ans;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] <= nums[n-1]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        if (nums[mid] <= target && nums[n-1] >= target) {
            l = mid;
            r = n-1;
        } else {
            l = 0; r = mid-1;
        }
        
        while(l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};