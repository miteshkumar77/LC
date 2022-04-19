// https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int prev = -1;
        int del = 0;
        int n = nums.size();
        for (int i = 0; i <= n; ++i) {
            if (prev >= 0 && ((i == n) || (nums[i] != nums[prev]))) {
                del += (i - prev - 1);
                prev = -1;
            }
            if (prev == -1 && ((i - del) % 2 == 0)) {
                prev = i;
            }
        }
        return del + (n - del) % 2;
    }
};