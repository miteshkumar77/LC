// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1); 
        
        for (int i = 0; i < nums.size(); ++i) {
            while(nums[i] != -1 && nums[i] != i && nums[nums[i]] != nums[i]) {
                swap(nums[i], nums[nums[i]]); 
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == -1) {
                return i; 
            }
        }
        return -1; 
    }
};