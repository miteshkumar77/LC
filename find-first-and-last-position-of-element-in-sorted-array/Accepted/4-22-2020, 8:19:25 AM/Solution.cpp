// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = firstOccurrence(nums, target, true); 
        if (i == -1) {
            return vector<int> {-1, -1}; 
        } else {
            return vector<int> {i, firstOccurrence(nums, target, false)}; 
        }
    }
    
    int firstOccurrence(vector<int>& nums, int target, bool first) {
        int L = 0; 
        int R = nums.size() - 1; 
        int ans = -1; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (nums[mid] > target) {
                R = mid - 1; 
            } else if (nums[mid] < target) {
                L = mid + 1; 
            } else {
                ans = mid; 
                if (first) {
                    R = mid - 1; 
                } else {
                    L = mid + 1; 
                }
            }
        }
        
        return ans; 
    }
};