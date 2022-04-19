// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dec(n+2, false);
        dec[n+1] = true;
        int prev = INT_MAX;
        for (int i = n; i >= 1; --i) {
            if (prev > nums[i-1]) {
                dec[i] = dec[i+1];
            } else { break; }
            prev = nums[i-1];
        }
        prev = INT_MIN;
        vector<bool> inc(n + 2, false);
        inc[0] = true;
        for (int i = 1; i <= n; ++i) {
            if (prev < nums[i-1]) {
                inc[i] = inc[i-1];
            } else { break; }
            prev = nums[i-1];
        }
        
        if (inc[n-1] || dec[1]) { return true; }
        for (int i = 2; i < n; ++i) {
            if (inc[i-1] && dec[i+1] && nums[i-2] < nums[i]) {
                return true;
            }
        }
        return false;
    }
};