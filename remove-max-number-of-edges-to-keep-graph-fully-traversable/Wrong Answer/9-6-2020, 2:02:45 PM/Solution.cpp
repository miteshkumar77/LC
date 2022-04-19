// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] > b[0]; 
        });
        vector<int> alicen(n + 1, -1); 
        vector<int> bobn(n + 1, -1); 
        function<int(int,vector<int>&)> find = [&] (int node, vector<int>& parent) -> int {
            if (parent[node] == -1) {
                return node; 
            }
            
            parent[node] = find(parent[node], parent); 
            return parent[node]; 
        };
        
        function<bool(int,int,vector<int>&)> onion = [&](int node1, int node2, vector<int>& parent) -> int {
            if (find(node1, parent) == find(node2, parent)) {
                return false; 
            }
            
            parent[find(node1, parent)] = find(node2, parent); 
            return true; 
        };
        
        int num_alex = 0; 
        int num_bob = 0; 
        int ans = 0; 
        for (auto edge : edges) {
            bool over_alex = false; 
            bool over_bob = false; 
            if (edge[0] == 3 || edge[0] == 1) {
                ++num_alex; 
                if (!onion(edge[1], edge[2], alicen)) {
                    over_alex = true; 
                    if (edge[0] != 3) {
                        ++ans; 
                    }
                }
            } 
            
            if (edge[0] == 3 || edge[0] == 2) {
                ++num_bob; 
                if (!onion(edge[1], edge[2], bobn)) {
                    over_bob = true; 
                    if (edge[0] != 3) {
                        ++ans; 
                    }
                }
            }
            if (over_alex && over_bob && edge[0] == 3) {
                ++ans; 
            }
        }
        
        if (num_alex < n - 1 || num_bob < n - 1) {
            return -1; 
        }
        
        return ans; 
    }
};