// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); ++i) {
            while(nums[i] != i + 1 && nums[i] <= nums.size() && nums[i] > 0 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1; 
            }
        }
        return nums.size() + 1; 
    }
};