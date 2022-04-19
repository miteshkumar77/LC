// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > connections.size()) {
            return -1; 
        }
        
        vector<vector<int>> graph(n); 
        for (auto edge : connections) {
            graph[edge[0]].push_back(edge[1]); 
            graph[edge[1]].push_back(edge[0]); 
        }
        
        int components = 0; 
        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int node) -> void {
            if (visited[node]) {
                return; 
            }
            
            visited[node] = true; 
            for (int neighbor : graph[node]) {
                dfs(neighbor); 
            }
        };
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++components; 
                dfs(i); 
            }
        }
        return components - 1; 
    }
};