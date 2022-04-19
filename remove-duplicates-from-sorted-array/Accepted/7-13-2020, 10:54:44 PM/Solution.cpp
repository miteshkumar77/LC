// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size(); 
        }
        
        return removeKDuplicates(nums, 1); 
        
    }
    
    
    int removeKDuplicates(vector<int>& nums, int k) {
        if (nums.size() <= k) {
            return nums.size(); 
        }
        
        int sz = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            
            if (i + k >= nums.size() || nums[i] != nums[i + k]) {
                nums[sz++] = nums[i]; 
            }
        }
        return sz; 
    }
};