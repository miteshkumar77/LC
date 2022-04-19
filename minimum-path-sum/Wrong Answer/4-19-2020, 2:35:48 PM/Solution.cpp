// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                int u = 0;
                int l = 0;
                if (i != 0) {
                    u = grid[i - 1][j]; 
                }
                
                if (j != 0) {
                    l = grid[i][j - 1];     
                }
                
                grid[i][j] += min(u, l); 
            }
        }
        
        return grid.back().back(); 
    }
};