// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] == 1) {
                suff[i] = suff[i + 1] + 1;
            }
        }
        int ans = 0;
        int pref = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, pref + suff[i+1]);
            if (nums[i] == 1) {
                ++pref;
            } else {
                pref = 0;
            }
        }
        
        return ans;
    }
};