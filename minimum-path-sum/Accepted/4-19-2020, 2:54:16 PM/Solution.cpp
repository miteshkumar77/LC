// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int u = 0;
                int l = 0;
                if (i != 0) {
                    u = grid[i - 1][j]; 
                } else {
                    u = -1;
                }
                
                if (j != 0) {
                    l = grid[i][j - 1];     
                } else {
                    l = -1;
                }
                
                if (u == -1 && l == -1) {
                    continue;
                } else if (u == -1) {
                    grid[i][j] += l;
                } else if (l == -1) {
                    grid[i][j] += u;
                } else {
                    grid[i][j] += min(u, l); 
                }
                // cout << grid[i][j] << ' ';
            }
            
            // cout << endl;
        }
         
        return grid.back().back(); 
    }
};