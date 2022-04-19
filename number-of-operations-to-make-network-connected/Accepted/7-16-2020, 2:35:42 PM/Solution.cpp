// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    typedef pair<int, int> pii; 
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<list<int> > graph(n, list<int>()); 
        for (vector<int> c : connections) {
            graph[c[0]].push_back(c[1]); 
            graph[c[1]].push_back(c[0]); 
        }
        vector<bool> visited (n, false); 
        vector<vector<bool> > visited_edges(n, vector<bool>(n, false)); 
        int redundant_edges = 0; 
        int components = 0; 

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++components;
                bfs(i, redundant_edges, visited, visited_edges, graph); 
            }
        }
        if (redundant_edges >= components - 1) {
            return components - 1;
        } else {
            return -1; 
        }
    }
    
    
    
    void bfs(int start, int& num_redundant, vector<bool>& visitedNodes, vector<vector<bool> >& visited_edges, vector<list<int> >& graph) {
        queue<int> q; 
        q.push(start); 
        while(!q.empty()) {
            int node = q.front(); q.pop(); 
            for (int neighbor : graph[node]) {
                if (!visited_edges[node][neighbor]) {
                    visited_edges[node][neighbor] = true;
                    visited_edges[neighbor][node] = true;
                    if (visitedNodes[neighbor]) {
                        ++num_redundant;
                    } else {
                        q.push(neighbor);
                        visitedNodes[neighbor] = true;
                    }
                }
            }
        }
    }
};