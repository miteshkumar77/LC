// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        /*
            dp[i][j] = max satisfaction if subset of dishes 1 ... i are completed
            at time j
        */
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int ans = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1e9));
        for (int i = 0; i <= n; ++i) dp[i][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i-1][j-1] + satisfaction[i-1]*j);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};