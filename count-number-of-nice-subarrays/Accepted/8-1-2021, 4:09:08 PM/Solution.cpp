// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ct(n+1, 0);
        ct[0] = 1;
        int t = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            t += nums[i] % 2;
            if (t >= k) {
                ans += ct[t-k];
            }
            ++ct[t];
        }
        return ans;
    }
};