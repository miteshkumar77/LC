// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size(), -1); 
        
        function<int(int)> find = [&](int a) -> int {
            if (parent[a] == -1) {
                return a; 
            }
            
            parent[a] = find(parent[a]); 
            return parent[a]; 
        };
        
        
        function<bool(int,int)> onion = [&](int a, int b) -> bool {
            int pa = find(a); 
            int pb = find(b); 
            if (pa == pb) {
                return false; 
            }
            
            parent[pa] = pb; 
            return true; 
        };
        
        
        for (auto edge : edges) {
            if (!onion(edge[0] - 1, edge[1] - 1)) {
                return edge; 
            }
        }
        return vector<int>(); 
    }
};