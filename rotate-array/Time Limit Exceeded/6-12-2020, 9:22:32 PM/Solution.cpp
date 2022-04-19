// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size(); 
        if (k == 0) {
            return; 
        }
        
        int tmp; 
        for (int i = 0; i < k; ++i) {
            tmp = nums.back(); 
            for (int j = 0; j < nums.size(); ++j) {
                swap(nums[j], tmp); 
            }
        }
    }
};