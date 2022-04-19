// https://leetcode.com/problems/maximum-number-of-points-with-cost

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(); int m = points[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0] = vector<int>(points[0].begin(), points[0].end());
        for (int i = 1; i < n; ++i) {
            int mx = INT_MIN+1; 
            for (int j = 0; j < m; ++j) {
                mx = max(mx-1, dp[i-1][j]);
                dp[i][j] = mx + points[i][j];
            }
            mx = INT_MIN+1; 
            for (int j = m-1; j >= 0; --j) {
                mx = max(mx-1, dp[i-1][j]);
                // if (i == n-1) cout << mx << ' ' << points[i][j] << endl;
                dp[i][j] = max(mx + points[i][j], dp[i][j]);
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};