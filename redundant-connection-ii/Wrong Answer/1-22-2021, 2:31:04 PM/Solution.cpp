// https://leetcode.com/problems/redundant-connection-ii

class Solution {
public:
    
    int dfs(const vector<unordered_map<int,int>>& graph, vector<int>& visited, int node) {
        if (visited[node] == 2) {
            return -1;
        }
        if (visited[node] == 1) {
            return 0;
        }
        ++visited[node];
        int ans = -1;
        int ret;
        for (auto [neighbor, index] : graph[node]) {
            ret = dfs(graph, visited, neighbor); 
            if (ret != -1) {
                ans = max(ans, max(index, ret)); 
            }
        }
        ++visited[node];
        return ans;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
            
        vector<unordered_map<int,int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0); 
        int zx = 0;
        for (auto& e : edges) {
            ++indegree[e[1]];
            ++outdegree[e[0]];
            graph[e[0]][e[1]] = zx;
            ++zx;
        }
        
        
        for (auto& e : edges) {
            if (indegree[e[1]] == 2 && indegree[e[0]] == 1) {
                return e;
            }
        }
        int ret;
        vector<int> visited(n + 1, 0); 
        for (int i = 1; i <= n; ++i) {
            ret = dfs(graph, visited, i);
            if (ret != -1) {
                return edges[ret];
            }
        }
        return edges.back(); 
        
    }
};