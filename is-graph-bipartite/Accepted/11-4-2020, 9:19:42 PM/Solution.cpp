// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, -1);
        function<bool(int,int)> dfs = [&](int node, int color) -> bool {
            if (dp[node] != -1) {
                return dp[node] == color;
            }
            
            dp[node] = color;
            for (int neighbor : graph[node]) {
                if (!dfs(neighbor, (color + 1) % 2)) {
                    return false;
                }
            }
            return true;
        };
        
        for (int i = 0; i < n; ++i) {
            if (dp[i] == -1) {
                if (!dfs(i, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};