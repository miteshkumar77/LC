// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> pr(n, -1);
        int idx = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j]+1) {
                    dp[i] = dp[j] + 1; pr[i] = j;
                }
            }
            if (dp[i] > dp[idx]) {
                idx = i;
            }
        }
        vector<int> ans;
        ans.reserve(dp[idx]);
        while(idx >= 0) {
            ans.push_back(nums[idx]);
            idx = pr[idx];
        }
        return ans;
    }
};