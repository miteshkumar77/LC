class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<bool>>> dp(n+1, 
            vector<vector<bool>>(m+1, vector<bool>(n + m + 1, false)));
        
        dp[0][0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1) {
                    dp[i][j][1] = (grid[i-1][j-1] == '(');
                    continue;
                }
                if (grid[i-1][j-1] == ')') {
                    dp[i][j][0] = dp[i][j-1][1] || dp[i-1][j][1];
                } else {
                    dp[i][j][n+m] = dp[i][j-1][n+m-1] || dp[i-1][j][n+m-1];
                }
                
                for (int k = 1; k < (n+m); ++k) {
                    int p = (grid[i-1][j-1] == '(') ? k-1 : k+1;
                    dp[i][j][k] = dp[i-1][j][p] || dp[i][j-1][p];
                }
            }
        }
        return dp[n][m][0];
    }
};