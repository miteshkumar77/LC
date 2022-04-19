// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0; int n = nums.size(); int r = n-1;
        for (int i = 0; i < n; ) {
            i = max(i, l);
            if (nums[i] == 0) {
                swap(nums[i], nums[l++]);
            } else if (nums[i] == 1) {
                swap(nums[i], nums[r--]);
            } else {
                ++i;
            }
        }
    }
};