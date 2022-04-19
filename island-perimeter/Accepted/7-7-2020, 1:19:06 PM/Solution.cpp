// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0; 
        array<int, 5> dirs {0, 1, 0, -1, 0}; 
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    for (int x = 1; x < 5; ++x) {
                        int new_i = i + dirs[x - 1]; 
                        int new_j = j + dirs[x]; 
                        if (new_i < 0 || new_i >= grid.size() || new_j < 0 || new_j >= grid[new_i].size() || grid[new_i][new_j] == 0) {
                            ++ans; 
                        }
                    }
                }
            }
        }
        return ans; 
    }
    
    
    
};