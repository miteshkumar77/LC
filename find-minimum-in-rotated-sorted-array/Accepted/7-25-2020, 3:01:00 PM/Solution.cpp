// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0; 
        int R = nums.size() - 1; 
        int ans = 0; 
        while(nums[L] > nums[R]) {
            int mid = L + (R - L)/2; 
            if (nums[mid] < nums[R]) {
                ans = mid; 
                R = mid - 1; 
            } else if (nums[mid] > nums[R]) {
                ans = mid + 1; 
                L = mid + 1; 
            }
        }
        return nums[ans]; 
    }
};