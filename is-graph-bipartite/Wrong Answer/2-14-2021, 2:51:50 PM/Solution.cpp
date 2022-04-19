// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colors) {
        if (colors[node] != -1) {
            return colors[node] = color;
        }
        colors[node] = color;
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, (color + 1) % 2, graph, colors)) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> colors(n, -1); 
        for (int node = 0; node < n; ++node) {
            if (colors[node] == -1) {
                if (!dfs(node, 0, graph, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
};