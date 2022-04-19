// https://leetcode.com/problems/redundant-connection-ii

class Solution {
public:
    
    bool isTree(vector<unordered_set<int>>& graph, int root, vector<bool>& visited, int& num_visited) {
        if (visited[root]) {
            return false;
        }
        visited[root] = true;
        ++num_visited;
        for (int neighbor: graph[root]) {
            if (!isTree(graph, neighbor, visited, num_visited)) {
                return false;
            }
        }
        return true;
        
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_set<int>> graph(n + 1, unordered_set<int>()); 
        vector<int> indegree(n + 1, 0);
        for (auto& e : edges) {
            graph[e[0]].insert(e[1]);
            ++indegree[e[1]];
        }
        
        for (int edgeidx = n - 1; edgeidx >= 0; --edgeidx) {
            auto e = edges[edgeidx];
            vector<bool> visited(n + 1, false);
            int num_visited = 0;
            int root = 0;
            graph[e[0]].erase(e[1]);
            --indegree[e[1]];
            for (int i = 1; i <= n; ++i) {
                if (indegree[i] == 0) {
                    root = i;
                    break;
                }
            }
            // cout << e[0] << ' ' << e[1] << ' ' << root << endl;
            if (isTree(graph, root, visited, num_visited) && num_visited == n) {
                return e;
            }
            graph[e[0]].insert(e[1]);
            ++indegree[e[1]];
        }
        return vector<int>(); 
        
        
        
    
    }
};