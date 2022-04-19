// https://leetcode.com/problems/all-paths-from-source-lead-to-destination

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> pre(n, false); vector<bool> post(n, false);
        vector<vector<int>> graph(n);
        for (auto const& e : edges) {
            graph[e[0]].push_back(e[1]);
        }
        
        function<bool(int)> dfs = [&](int node) -> bool {
            if (pre[node]) {
                if (post[node]) return true;
                return false;
            }
            pre[node] = true;
            for (int neighbor : graph[node]) {
                if (!dfs(neighbor)) return false;
            }
            if (node == destination) { post[node] = true; return true; }
            if (graph[node].size() == 0) return false;
            post[node] = true;
            return true;
        };
        
        return dfs(source);
    }
};