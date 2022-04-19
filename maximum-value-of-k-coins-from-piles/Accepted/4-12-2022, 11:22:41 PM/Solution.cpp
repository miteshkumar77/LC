// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        for (auto &p : piles) {
            for (int i = 1; i < p.size(); ++i) {
                p[i] += p[i-1];
            }
        }
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int p = 1; p <= n; ++p) {
            for (int m = 1; m <= k; ++m) {
                int ans = INT_MIN;
                for (int mp = max(0, (int)(m-piles[p-1].size())); mp < m; ++mp) {
                    ans = max(ans, piles[p-1][m-mp-1] + dp[p-1][mp]);
                }
                ans = max(ans, dp[p-1][m]);
                dp[p][m] = ans;
            }
        }
        return dp[n][k];
    }
};