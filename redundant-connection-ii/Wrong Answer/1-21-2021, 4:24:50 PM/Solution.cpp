// https://leetcode.com/problems/redundant-connection-ii

class Solution {
public:
    int cycleEdge(vector<unordered_map<int,int>>& graph, int root, vector<int>& visited) {
        if (visited[root] == 1) {
            return 0;
        }
        
        if (visited[root] == 2) {
            return -1;
        }
        
        ++visited[root];
        int ans = -1;
        for (auto [neighbor, edgeIdx] : graph[root]) {
            int ret = cycleEdge(graph, neighbor, visited); 
            if (ret != -1) {
                ans = max(ans, max(ret, edgeIdx)); 
            }
        }
        ++visited[root];
        return ans;
    }
    
    void dfs(vector<unordered_map<int,int>>& graph, int root, vector<int>& visited) {
        ++visited[root];
        if (visited[root] > 1) return;
        
        for (auto [neighbor, edgeIdx] : graph[root]) {
            dfs(graph, neighbor, visited);
        }
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> visited(n + 1, 0); 
        vector<int> indegree(n + 1, 0); 
        int root = 0;
        vector<unordered_map<int,int>> graph(n + 1); 
        for (int i = 0; i < n; ++i) {
            graph[edges[i][0]].insert({edges[i][1], i}); 
            ++indegree[edges[i][1]]; 
            if (indegree[edges[i][0]] == 0) {
                root = edges[i][0];
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            int ans = cycleEdge(graph, i, visited); 
            if (ans != -1) {
                return edges[ans];
            }
        }
        
        fill(visited.begin(), visited.end(), 0); 
        dfs(graph, root, visited); 
        
        int extraNode = -1;
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == 2) {
                extraNode = i;
                break;
            }
        }
        
        int edgeIdx = 0;
        for (int i = 0; i < n; ++i) {
            
            if (edges[i][1] == extraNode) {
                edgeIdx = i;
            }
        }
        return edges[edgeIdx];
        
        
    
    }
};