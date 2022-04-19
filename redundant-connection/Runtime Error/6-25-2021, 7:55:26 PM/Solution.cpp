// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n, -1);
        
        function<int(int)> find = [&](int node) -> int {
            if (parent[node] == -1) {
                return node;
            } else {
                parent[node] = find(parent[node]);
                return parent[node];
            }
        };
        
        function<bool(int,int)> onion = [&](int a, int b) -> bool {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return false;
            parent[pa] = pb;
            return true;
        };
        
        for (auto e : edges) {
            if (!onion(e[0], e[1])) {
                return e;
            }
        }
        return vector<int>();
    }
};