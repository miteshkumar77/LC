// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1) {
            return 0; 
        }
        obstacleGrid[0][0] = 1; 
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[i].size(); ++j) {
                if (i == 0 && j == 0) continue; 
                if (obstacleGrid[i][j] == 0) {
                    if (i != 0) {
                        obstacleGrid[i][j] += obstacleGrid[i - 1][j]; 
                    }
                    if (j != 0) {
                        obstacleGrid[i][j] += obstacleGrid[i][j - 1]; 
                    }
                } else {
                    obstacleGrid[i][j] = 0; 
                }
            }
        }
        return obstacleGrid.back().back(); 
    }
};