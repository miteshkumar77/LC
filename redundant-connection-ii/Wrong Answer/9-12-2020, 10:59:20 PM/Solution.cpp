// https://leetcode.com/problems/redundant-connection-ii

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        
        int n = edges.size(); 
        
        vector<vector<int>> graph(n + 1, vector<int>());
        
        
        for (int e = 0; e < edges.size(); ++e) {
            graph[edges[e][0]].push_back(edges[e][1]); 
        }
        
        int root = 0; 
        
        
        vector<int> numpaths(n + 1, 0); 
        
        function<void(int)> dfs = [&](int node) -> void {
            ++numpaths[node]; 
            if (numpaths[node] > 1) {
                return; 
            }
            
            
            for (int neighbor : graph[node]) {
                dfs(neighbor); 
            }
            root = node; 
        };
        
        
        for (int i = 1; i <= n; ++i) {
            dfs(i); 
        }
        
        numpaths = vector<int>(n + 1, 0); 
        dfs(root); 
        
        vector<int> ans; 
        
        for (auto edge : edges) {
            if (numpaths[edge[1]] > 1) {
                ans = edge; 
            }
        }
        return ans; 
    }
};