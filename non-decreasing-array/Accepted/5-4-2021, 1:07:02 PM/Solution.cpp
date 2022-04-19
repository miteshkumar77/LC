// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(INT_MAX);
        vector<bool> suff(n, true);
        int prev = INT_MAX;
        int sr = true;
        for (int i = n - 1; i >= 0; --i) {
            if (prev < nums[i]) {
                suff[i] = false;
            } else {
                suff[i] = sr;
            }
            prev = nums[i];
            sr = suff[i];
        }
        int pr = true;
        prev = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (prev <= nums[i + 1] && pr && suff[i + 1]) {
                return true;
            }
            pr = pr && nums[i] >= prev;
            prev = nums[i];
        }
        return false;
    }
};