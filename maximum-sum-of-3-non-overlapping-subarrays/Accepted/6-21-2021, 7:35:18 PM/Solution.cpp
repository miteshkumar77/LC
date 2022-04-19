// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = n-1; i >= 0; --i) pref[i] = nums[i] + pref[i+1];
        vector<vector<int>> dp(4, vector<int>(n + 1, INT_MIN));
        vector<vector<int>> prev(4, vector<int>(n + 1, INT_MAX));
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 0;
            prev[0][j] = 0;
        }
        for (int i = 1; i <= 3; ++i) {
            int mx = INT_MIN;
            for (int j = n - i * k; j >= 0; --j) {
                mx = max(mx, dp[i-1][j+k]);
                if (pref[j] - pref[j+k] + mx >= dp[i][j+1]) {
                    dp[i][j] = pref[j] - pref[j+k] + mx;
                    prev[i][j] = j;
                } else {
                    dp[i][j] = dp[i][j+1];
                    prev[i][j] = prev[i][j+1];
                }
            }
        }
        int j = 0;
        vector<int> ans;
        for (int i = 3; i >= 1; --i) {
            ans.push_back(prev[i][j]);
            j = prev[i][j] + k;
        }
        return ans;
    }
};