// https://leetcode.com/problems/unique-paths-iii

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0; 
        int m = grid.size(); int n = grid[0].size();
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        
        function<void(int,int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) {
                return;
            }
            cout << i << ' ' << j << endl; 
            if (grid[i][j] == 2) {
                ++ans;
                return;
            }
            grid[i][j] = -1; 
            for (int x = 0; x < 4; ++x) {
                dfs(i + dirs[x], j + dirs[x + 1]); 
            }
            grid[i][j] = 0; 
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i,j); 
                    return ans; 
                }
            }
        }
        return ans; 
    }
};