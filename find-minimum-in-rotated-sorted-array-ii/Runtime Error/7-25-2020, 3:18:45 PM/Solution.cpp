// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0; int R = nums.size() - 1; 
        int ans = 0; 
        
        while(L <= R && nums[L] == nums[R]) {
            ++L; 
        }
        
        
        while(L < R) {
            int mid = L + (R - L)/2; 
            
            if (nums[mid] > nums[R]) {
                L = mid + 1; 
            } else if (nums[mid] <= nums[R]) {
                R = mid - 1; 
            }
        }
        
        return nums[L]; 
    }
};