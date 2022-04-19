// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (i + k >= n || nums[i] != nums[i+k]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};