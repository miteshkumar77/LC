// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0; 
        }
        vector<vector<int>> graph(matrix.size() * matrix[0].size(), vector<int>()); 
        int m = matrix.size(); int n = matrix[0].size(); 
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                // cout << i * m + j << ' ';
                for (int k = 0; k < 4; ++k) {
                    int ni = dirs[k] + i; 
                    int nj = dirs[k + 1] + j; 
                    if (ni < m && nj < n && ni >= 0 && nj >= 0 && matrix[ni][nj] > matrix[i][j]) {
                        graph[i * n + j].push_back(ni * n + nj);
                    }
                }
            }
        }
        
        
        vector<bool> visited1(m * n, false);
        stack<int> toporder; 
        
        function<void(int)> dfs1 = [&] (int node) -> void {
            visited1[node] = true; 
            for (int n : graph[node]) {
                if (!visited1[n]) {
                    dfs1(n); 
                }
            }
            toporder.push(node); 
        };
        
        for (int i = 0; i < m * n; ++i) {
            if (!visited1[i]) {
                dfs1(i); 
            }
        }
        
        
        vector<int> dists(m * n, -1); 
        int ans = 0; 
        while(!toporder.empty()) {
            
            int node = toporder.top(); toporder.pop(); 
            if (dists[node] == -1) {
                dists[node] = 1; 
            }
            ans = max(ans, dists[node]); 
            for (int n : graph[node]) {
                dists[n] = max(dists[node] + 1, dists[n]); 
            }
        }
        return ans; 
        
    }
};