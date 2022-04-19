// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    typedef pair<int, int> pii; 
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1; 
        }
        vector<list<int> > graph(n, list<int>()); 
        for (vector<int> c : connections) {
            graph[c[0]].push_back(c[1]); 
            graph[c[1]].push_back(c[0]); 
        }
        vector<bool> visited (n, false); 
        int components = 0; 

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++components;
                bfs(i, visited, graph); 
            }
        }
        
        return components - 1; 
        
    }
    
    
    
    void bfs(int start, vector<bool>& visitedNodes, vector<list<int> >& graph) {
        queue<int> q; 
        q.push(start); 
        while(!q.empty()) {
            int node = q.front(); q.pop(); 
            for (int neighbor : graph[node]) {
                if (!visitedNodes[neighbor]) {
                    q.push(neighbor); visitedNodes[neighbor] = true; 
                }
            }
        }
    }
};