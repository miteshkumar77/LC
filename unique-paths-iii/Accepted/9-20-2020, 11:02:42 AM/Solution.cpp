// https://leetcode.com/problems/unique-paths-iii

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0; 
        int m = grid.size(); int n = grid[0].size();
        int unvisited = 0; 
        int si;
        int sj; 
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    ++unvisited;
                    si = i;
                    sj = j;
                }
                if (grid[i][j] == 0) {
                    ++unvisited;
                }
            }
        }
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        
        function<void(int,int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) {
                return;
            }
            if (grid[i][j] == 2) {
                if (unvisited == 0) {
                    ++ans;
                }
                return;
            }
            grid[i][j] = -1; 
            --unvisited;
            for (int x = 0; x < 4; ++x) {
                dfs(i + dirs[x], j + dirs[x + 1]); 
            }
            grid[i][j] = 0; 
            ++unvisited;
        };
        
        dfs(si, sj); 
        return ans; 
    }
};