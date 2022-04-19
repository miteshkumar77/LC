// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); 
        for (int i = 2; i < n; ++i) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                int x = 0; 
                int j = i; 
                while(j < n && nums[j] == nums[i]) {
                    ++j; ++x; 
                }
                for (int k = i; k < n; ++k) {
                    if (k + x < n) {
                        nums[k] = nums[k + x]; 
                    }
                }
                n -= x; 

            }
        }
        return n; 
    }
};