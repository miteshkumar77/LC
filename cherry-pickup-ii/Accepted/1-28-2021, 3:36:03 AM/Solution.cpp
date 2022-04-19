// https://leetcode.com/problems/cherry-pickup-ii

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n, vector<int>(n, -1))); 
        dp[1][0][n - 1] = grid[0][0] + grid[0][n - 1];
        if (n == 1) {
            dp[1][0][n - 1] -= grid[0][0];
        }
        int ans = 0;
        for (int row = 2; row <= m; ++row) {
            for (int r1 = 0; r1 < n; ++r1) {
                for (int r2 = 0; r2 < n; ++r2) {
                    
                    
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            if (r1 + i >= 0 && r1 + i < n && r2 + j >= 0 && r2 + j < n) {
                                dp[row][r1][r2] = max(dp[row][r1][r2], dp[row - 1][r1 + i][r2 + j]); 
                            }
                        }
                    }
                    if (dp[row][r1][r2] != -1) {
                        dp[row][r1][r2] += grid[row - 1][r1] + grid[row - 1][r2];
                        if (r1 == r2) {
                            dp[row][r1][r2] -= grid[row - 1][r1];
                        }
                    }
                    // cout << dp[row][r1][r2] << ' ';
                    ans = max(ans, dp[row][r1][r2]); 
                }
                // cout << endl;
            }
        }
        
        return ans;
        
    }
};