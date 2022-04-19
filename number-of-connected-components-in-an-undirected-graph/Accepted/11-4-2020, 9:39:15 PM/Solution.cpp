// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
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
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) ++ans;
            dfs(i);
        }
        return ans;
        
        
    }
};