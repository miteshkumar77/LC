// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0; int R = nums.size() - 1; 
        int ans = nums.size(); 
        int mid; 
        while(L <= R) {
            mid = L + (R - L)/2; 
            if (nums[mid] < target) {
                L = mid + 1; 
            } else if (nums[mid] > target) {
                R = mid - 1; 
                ans = mid; 
            } else {
                return mid; 
            }
        }
        return ans; 
    }
};