// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool find(vector<int>& nums, int target, int l, int r) {
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int br = 0;
        int mid;
        while(l <= r && nums[l] >= nums[r]) {
            if (nums[l] > nums[r]) {
                mid = l + (r - l)/2;
                if (nums[mid] < nums[r]) {
                    br = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                    br = l;
                }
            } else {
                br = r--;
                if (nums[br] == target) return true;
            }
        }
        
        return find(nums, target, 0, br-1) || find(nums, target, br, n-1);
    }
};