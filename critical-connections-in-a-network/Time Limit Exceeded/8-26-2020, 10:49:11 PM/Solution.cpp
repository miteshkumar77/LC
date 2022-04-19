// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> parent1(n, -1); 
        function<int(int,vector<int>&)> find = [&](int node, vector<int>& parent) -> int {
            if (parent[node] == -1) {
                return node; 
            }
            
            parent[node] = find(parent[node], parent); 
            return parent[node]; 
        };
        
        function<bool(int,int,vector<int>&)> onion = [&](int n1, int n2, vector<int>& parent) -> bool {
            if (find(n1, parent) == find(n2, parent)) {
                return false; 
            }
            
            parent[n1] = n2; 
            find(n1, parent); 
            return true; 
        };
        
        
        vector<vector<int>> treeEdges;
        
        for (auto connection: connections) {
            if (onion(connection[0], connection[1], parent1)) {
                treeEdges.push_back(connection); 
            }
        }
        
        
        unordered_map<int, unordered_set<int>> graph; 
        
        for (auto connection: connections) {
            graph.insert(make_pair(connection[0], unordered_set<int>())); 
            graph[connection[0]].insert(connection[1]); 
            graph.insert(make_pair(connection[1], unordered_set<int>())); 
            graph[connection[1]].insert(connection[0]); 
        }
        
        vector<vector<int>> ans; 
        for (auto edge : treeEdges) {
            graph[edge[0]].erase(edge[1]); 
            graph[edge[1]].erase(edge[0]); 
            if (!reachable(edge[0], edge[1], graph)) {
                ans.push_back(edge); 
            }
            graph[edge[0]].insert(edge[1]); 
            graph[edge[1]].insert(edge[0]); 
        }
        return ans; 
    }
    
    
    bool reachable(int src, int dest, unordered_map<int, unordered_set<int>>& graph) {
        unordered_set<int> visited; 
        function<bool(int,int)> dfs = [&](int src, int dest) -> bool {
            if (visited.find(src) != visited.end()) {
                return false; 
            }
            
            if (src == dest) {
                return true; 
            }
            
            visited.insert(src); 
            
            for (int n : graph[src]) {
                if (dfs(n, dest)) {
                    return true; 
                } 
            }
            return false; 
        };
        
        return dfs(src, dest); 
    }
};