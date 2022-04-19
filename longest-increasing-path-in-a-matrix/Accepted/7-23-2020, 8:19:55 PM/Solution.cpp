// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0; 
        }
        int m = matrix.size(); int n = matrix[0].size(); 
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        vector<vector<int> > dist(m, vector<int>(n, -1));
        
        
        int ans = 0; 
        
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (dist[i][j] != -1) {
                return dist[i][j]; 
            }
            dist[i][j] = 0; 
            int act = 0; 
            for (int x = 0; x < 4; ++x) {
                int ni = dirs[x] + i; int nj = dirs[x + 1] + j; 
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && matrix[i][j] < matrix[ni][nj]) {
                    act = max(act, dfs(ni, nj));
                }
            }
            dist[i][j] = 1 + act; 
            return dist[i][j]; 
        };
        
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] == -1) {
                    ans = max(dfs(i, j), ans); 
                }
            }
        }
        return ans; 
    }
};