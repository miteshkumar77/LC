// https://leetcode.com/problems/cherry-pickup

class Solution {
public:
    
    int m;
    int n;
    array<int, 3> dirs{0, 1, 0};
    int sol(int i1, int j1, int i2, int j2, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp) {
        if (dp[i1][j1][i2][j2] != -1) {
            return dp[i1][j1][i2][j2];
        }
        
        if (grid[i1][j1] == -1 || grid[i2][j2] == -1) {
            return -2;
        }
        
        if (i1 == m - 1 && j1 == n - 1) {
            return grid[i1][j1];
        }
        
        int ans = -2;
        for (int d1 = 0; d1 < 2; ++d1) {
            for (int d2 = 0; d2 < 2; ++d2) {
                int ni1 = i1 + dirs[d1];
                int nj1 = j1 + dirs[d1 + 1];
                int ni2 = i2 + dirs[d2];
                int nj2 = j2 + dirs[d2 + 1];
                if (ni1 < m && nj1 < n && ni2 < m && nj2 < n) {
                    ans = max(ans, sol(ni1, nj1, ni2, nj2, grid, dp)); 
                }
            }
        }
        
        if (ans != -2) {
            if (i1 == i2 && j1 == j2) {
                ans += grid[i1][j1];
            } else {
                ans += grid[i1][j1] + grid[i2][j2];
            }
        }
        dp[i1][j1][i2][j2] = ans;
        return ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
       m = grid.size();
       n = grid[0].size(); 
        
        /*
            dp[i][j][k][l] = max cherries if p1 picks up i, j and p2 picks up k, l
        */
        
        
        vector<vector<vector<vector<int>>>> dp(
            m,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(
                    m,
                    vector<int>(n, -1)
                )
            )
        );
        
        return max(0, sol(0, 0, 0, 0, grid, dp));
        
                
        
    }
};