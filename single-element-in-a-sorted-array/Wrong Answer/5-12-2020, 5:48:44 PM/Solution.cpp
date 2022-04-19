// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int L = 0; 
        int R = nums.size() - 1; 

        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (mid < nums.size() - 1 && nums[mid + 1] == nums[mid - 1]) {
                if (mid % 2 == 0) {
                    L = mid + 1; 
                } else {
                    R = mid - 1; 
                }
            } else if (mid > 0 && nums[mid - 1] == nums[mid]) {
                if (mid % 2 == 0) {
                    R = mid - 1; 
                } else {
                    L = mid + 1; 
                }
            } else {
                return nums[mid]; 
            }
        }
        
        return -1; 
        
    }
};
