// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    array<int, 5> dirs{0, 1, 0, -1, 0};
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        int ans = 1;
        for (int x = 0; x < 4; ++x) {
            ans += dfs(i + dirs[x], j + dirs[x+1], grid);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }
};