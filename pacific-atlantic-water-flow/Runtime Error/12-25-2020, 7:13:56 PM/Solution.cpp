// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        /*
        -1 -> neither
         0 -> not yet calculated
         1 -> atlantic only
         2 -> pacific only
         3 -> both atlantic and pacific
        */
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        
        function<int(int,int,int)> dfs = [&](int i, int j, int parentHeight) -> int {
            
            if (i < 0 || j < 0) {
                return 2;
            } else if (i >= m || j >= n) {
                return 1;
            } else if (matrix[i][j] > parentHeight) {
                return -1;
            }
            
            if (visited[i][j] != 0) {
                return visited[i][j];
            }
            
            visited[i][j] = -1;
            bool atlantic = false;
            bool pacific = false;
            for (int dir = 0; dir < 4; ++dir) {
                int a = dfs(i + dirs[dir], j + dirs[dir + 1], matrix[i][j]);
                if (a == 1) {
                    atlantic = true;
                } else if (a == 2) {
                    pacific = true;
                } else if (a == 3) {
                    atlantic = true;
                    pacific = true;
                }
            }
            
            if (atlantic && pacific) {
                visited[i][j] = 3;
            } else if (!(atlantic || pacific)) {
                visited[i][j] = -1;
            } else if (atlantic) {
                visited[i][j] = 1;
            } else {
                visited[i][j] = 2;
            }
            
            return visited[i][j];
        };
        vector<vector<int>> ans;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (dfs(r, c, INT_MAX) == 3) {
                    ans.push_back({r, c});
                }
            }
        }
        
        return ans;
    }
};