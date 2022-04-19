// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return vector<vector<int>>();
        }
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        /*
         0 -> not yet calculated
         1 -> atlantic only
         2 -> pacific only
         3 -> both atlantic and pacific
        */
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        
        function<void(int,int,int,int)> dfs = [&](int i, int j, int flag, int parentHeight) -> void {
            if (i >= m || j >= n || i < 0 || j < 0 || parentHeight > matrix[i][j]) {
                return;
            }
            
            if (visited[i][j] == flag || visited[i][j] == 3) return;
            
            if (visited[i][j] != 0) {
                visited[i][j] = 3;
            } else {
                visited[i][j] = flag;
            }
            
            for (int x = 0; x < 4; ++x) {
                dfs(i + dirs[x], j + dirs[x + 1], flag, matrix[i][j]);
            }
        };
        
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 || c == 0) {
                    dfs(r, c, 1, INT_MIN);
                }
                if (r == m - 1 || c == n - 1) {
                    dfs(r, c, 2, INT_MIN);
                }
            }
        }
        
        vector<vector<int>> ans;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (visited[r][c] == 3) {
                    ans.push_back({r, c});
                }
            }
        }
        
        return ans;
    }
};