// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{bound(target, nums, true) + 1, bound(target, nums, false) - 1}; 
    }
    
    
    
    int bound(int target, vector<int>& nums, bool lower) {
        int ans = 0; 
        int L = 0; int R = nums.size() - 1; 
        bool found = false; 
        while(L <= R) {
            int mid = L + (R - L)/2;
            if (nums[mid] > target) {
                if (!lower) {
                    ans = mid; 
                }
                R = mid - 1; 
            } else if (nums[mid] < target) {
                if (lower) {
                    ans = mid; 
                }
                L = mid + 1; 
            } else {
                found = true; 
                if (lower) {
                    R = mid - 1; 
                    ans = R; 
                } else {
                    L = mid + 1; 
                    ans = L; 
                }
            }
        }
        return found?ans:-1; 
    }
};