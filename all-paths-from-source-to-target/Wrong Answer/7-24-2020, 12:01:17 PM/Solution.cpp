// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<bool> visited(n, false); 
        
        
        vector<vector<vector<int>>> paths(n, vector<vector<int>>()); 
        paths[0].push_back(vector<int>{0}); 
        function<void(int)> dfs = [&] (int node) -> void {
            // visited[node] = true; 
            for (int neighbor : graph[node]) {
                if (visited[neighbor]) continue; 
                for (vector<int> path : paths[node]) {
                    paths[neighbor].push_back(path); 
                    paths[neighbor].back().push_back(neighbor); 
                    dfs(neighbor);
                }
            }
        };
        dfs(0); 
        return paths.back(); 
    }
};