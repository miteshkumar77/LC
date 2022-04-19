// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int bs(vector<int>& a, int target, bool lower) {
        int l = 0;
        int r = a.size() - 1;
        int ans = -1;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (a[mid] < target) {
                l = mid + 1;
            } else if (a[mid] > target) {
                r = mid - 1;
            } else {
                ans = mid;
                if (lower) {
                    r = mid - 1;    
                } else {
                    l = mid + 1;
                }
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        return {
            bs(nums, target, true),
            bs(nums, target, false)
        };
         
    }
};