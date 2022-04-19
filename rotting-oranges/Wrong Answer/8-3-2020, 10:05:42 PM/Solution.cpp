// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    typedef array<int, 2> pii; 
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size(); int N = grid[0].size(); 
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        
        int days = 0; 
        
        while(true) {
            bool made_change = false; 
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (grid[i][j] == 1) {
                        for (int x = 0; x < 4; ++x) {
                            int ni = i + dirs[x]; int nj = j + dirs[x + 1]; 
                            if (ni >= 0 && nj >= 0 && ni < M && nj < N && grid[ni][nj] == 2) {
                                grid[i][j] = -2; 
                                made_change = true; 
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (grid[i][j] == -2) {
                        grid[i][j] = 2; 
                    }
                }
            }
            if (!made_change) {
                break; 
            }
            ++days; 
        }
        return days; 
        
        
    }
    
    
    
};