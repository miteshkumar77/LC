// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int N = graph.size(); 
        vector<bool> visited(N, false); 
        
        
        vector<vector<int>> ans; 
        vector<int> path; 
        function<void(int)> dfs = [&] (int node) -> void {
            // visited[node] = true; 
            path.push_back(node); 
            if (node == N - 1) {
                ans.push_back(path); 
            } else {
                for (int neighbor : graph[node]) {
                    dfs(neighbor); 
                }
            }
            path.pop_back(); 
        };
        dfs(0); 
        return ans;  
    }
};