// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int L = 0; 
        int R = nums.size() - 1;
        int i = 0; 
        while(L < R && i <=R) {
            while(L < R && nums[L] == 0) {
                ++L; 
            }
            while(R > L && nums[R] == 2) {
                --R; 
            }
            if (i <= L) {
                i = L; 
            }
                if (nums[i] == 2) {
                    swap(nums[R--], nums[i]); 
                } else if (nums[i] == 0) {
                    swap(nums[L++], nums[i]); 
                } else {
                    ++i; 
                }
        
        }
    }
};