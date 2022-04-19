// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    typedef array<int, 2> pii; 
    int orangesRotting(vector<vector<int>>& grid) {
        
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        int num_fresh = 0; 
        for (auto v : grid) {
            for (auto i : v) {
                num_fresh += (i == 1); 
            }
        }
        
        function<int()> mark = [&] () -> int {
            
            int total_expanded = 0; 
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[i].size(); ++j) {
                    if (grid[i][j] == 1) {
                        for (int x = 0; x < 4; ++x) {
                            int ni = i + dirs[x]; int nj = j + dirs[x + 1]; 
                            
                            if (ni >= 0 && nj >= 0 && ni < grid.size() && 
                                nj < grid[ni].size() && grid[ni][nj] == 2) {
                                grid[i][j] = -1; 
                                break; 
                            }
                        }
                    }
                }
            }
            
            
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[i].size(); ++j) {
                    if (grid[i][j] == -1) {
                        grid[i][j] = 2; 
                        ++total_expanded; 
                        --num_fresh; 
                    }
                }
            }
            return total_expanded; 
        };
        int days = 0; 
        while(true) {
            if (!(mark() > 0)) {
                break; 
            }
            ++days; 
        }
        if (num_fresh != 0) {
            return -1; 
        } else {
            return days; 
        }
        
    }
    
    // [[2,1,1],
  //\   [0,1,1],
  //    [1,0,1]]
    
    
};