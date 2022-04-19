// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /// [1,1,1,2,2,3]
        /// [1,1,2,2,3,3]
        
        int w = 0;
        
        for (int r = 0; r < nums.size(); ++r) {
            if (w - 2 >= 0 && nums[r] == nums[w - 2]) {
                continue;
            }
            nums[w++] = nums[r];
        }
        return w;
    }
};