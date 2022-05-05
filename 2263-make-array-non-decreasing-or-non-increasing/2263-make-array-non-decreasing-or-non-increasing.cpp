class Solution {
public:
    int help(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(1001, 0));
        for (int i = 1; i <= n; ++i) {
            int premin = INT_MAX;
            for (int j = 0; j < 1001; ++j) {
                premin = min(premin, dp[i-1][j]);
                dp[i][j] = premin + abs(nums[i-1] - j);
            }
        }
        return *min_element(dp[n].begin(), dp[n].end());
    }
    int convertArray(vector<int>& nums) {
        int ans = help(nums);
        reverse(nums.begin(), nums.end());
        return min(ans, help(nums));
    }
};