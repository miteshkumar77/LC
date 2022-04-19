// https://leetcode.com/problems/maximum-number-of-points-with-cost

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(); int m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        dp[0] = vector<long long>(points[0].begin(), points[0].end());
        for (int i = 1; i < n; ++i) {
            long long mx = INT_MIN+1; 
            for (int j = 0; j < m; ++j) {
                mx = max(mx-1, dp[i-1][j]);
                dp[i][j] = mx + (long long)points[i][j];
            }
            mx = INT_MIN+1; 
            for (int j = m-1; j >= 0; --j) {
                mx = max(mx-1, dp[i-1][j]);
                // if (i == n-1) cout << mx << ' ' << points[i][j] << endl;
                dp[i][j] = max(mx + (long long)points[i][j], dp[i][j]);
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};