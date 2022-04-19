// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    
    void dfs(const vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, int node) {
        if (node == graph.size() - 1) {
            ans.push_back(path);
            return;
        }
        
        for (int neighbor : graph[node]) {
            path.push_back(neighbor);
            dfs(graph, ans, path, neighbor);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(const vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path{0};
        dfs(graph, ans, path, 0);
        return ans;
    }
};