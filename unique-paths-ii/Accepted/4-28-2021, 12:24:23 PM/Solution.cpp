// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) {
            return 0;
        }
        int m = obstacleGrid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -1;
                    continue;
                }
                if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = 1;
                    continue;
                }
                
                if (i != 0 && obstacleGrid[i - 1][j] > 0) {
                    obstacleGrid[i][j] += obstacleGrid[i - 1][j]; 
                }
                if (j != 0 && obstacleGrid[i][j - 1] > 0) {
                    obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                } 
            }
        }
        return max(obstacleGrid[n - 1][m - 1], 0);
    }
};