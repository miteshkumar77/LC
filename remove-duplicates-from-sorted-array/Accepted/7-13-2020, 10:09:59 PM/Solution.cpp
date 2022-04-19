// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size(); 
        }
        int sz = 1;
        int last = nums[0]; 
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != last) {
                last = nums[i]; 
                nums[sz++] = last; 
            }
        }
        return sz; 
    }
};