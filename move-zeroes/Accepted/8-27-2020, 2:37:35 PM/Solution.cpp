// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int r = 0, w = 0; r < nums.size(); ++r) {
            if (nums[r] != 0) {
                swap(nums[w++], nums[r]); 
            }
        }
    }
};