// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto e : edges) {
            graph[e[0]].insert(e[1]);
        }
        vector<int> ts; 
        ts.reserve(n);
        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int node) -> void {
            if (visited[node]) {
                return;
            }
            visited[node] = true;
            
            for (int neighbor : graph[node]) {
                dfs(neighbor);
            }
            ts.push_back(node);
        };
        
        for (int i = 0; i < n; ++i) {
            dfs(i);
        }
        
        for (int i = 0; i < n; ++i) visited[i] = false;
        
        int ans = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            if (!visited[ts[i]]) {
                ++ans;
            }
            
            visited[ts[i]] = true;
            for (int n : graph[ts[i]]) {
                visited[n] = true;
            }
        }
        return ans;
        
    }
};