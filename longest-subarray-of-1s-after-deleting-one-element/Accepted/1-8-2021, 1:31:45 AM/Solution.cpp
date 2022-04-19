// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int num_zeros = 0;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) ++num_zeros;
            while(num_zeros > 1) {
                if (nums[j++] == 0) --num_zeros;
            }
            
            ans = max(ans, i - j);
        }
        return ans;
    }
};