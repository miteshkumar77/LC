// https://leetcode.com/problems/count-sub-islands

class Solution {
public:
    array<int, 5> dirs{0, 1, 0, -1, 0};
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int i, int j, bool& glob) {
        int n = grid2.size(); int m = grid2[0].size();
        if (i < 0 || i >=n || j < 0 || j >= m) return;
        if (visited[i][j]) return;
        if (grid2[i][j] == 0) return;
        visited[i][j] = true;
        if (grid1[i][j] == 0) glob = false;
        for (int x = 0; x < 4; ++x) {
            dfs(grid1, grid2, visited, i + dirs[x], j + dirs[x+1], glob);
        }
        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size(); int m = grid2[0].size();
        vector<vector<bool>> visited(grid2.size(), vector<bool>(grid2[0].size(), false));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    bool glob = true;
                    dfs(grid1, grid2, visited, i, j, glob); ans += (int)glob;
                }
            }
        }
        return ans;
    }
};