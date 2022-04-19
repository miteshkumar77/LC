// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        vector<int> ct(nums.size(), 0); 
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= nums.size() && nums[i] > 0) {
                ++ct[nums[i] - 1]; 
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (ct[i] == 0) {
                return i + 1; 
            }
        }
        return ct.size() + 1; 
    }
};