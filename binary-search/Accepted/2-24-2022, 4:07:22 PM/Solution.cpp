// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size(); --r;
        int mid;
        while(l < r) {
            mid = l + (r - l)/2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[r] == target ? r : -1;
    }
};