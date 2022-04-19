// https://leetcode.com/problems/freedom-trail

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = key.length();
        int m = ring.length();
        vector<vector<int>> dp(n+1, vector<int>(m, (int)(1e9 + 7)));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ring[j] != key[i-1]) continue;
                for (int k = 0; k < m; ++k) {
                    int dist = min((k + m - j) % m, (j + m - k) % m) + 1;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + dist);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};