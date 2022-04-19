// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevmin(n, 0);
        prevmin[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            prevmin[i] = min(prevmin[i - 1], nums[i]);
        }
        int suffmax = nums.back();
        for (int i = n - 2; i >= 1; --i) {
            if (prevmin[i - 1] < nums[i] && nums[i] < suffmax) {
                return true;
            }
            suffmax = max(suffmax, nums[i]);
        }
        return false;
    }
};