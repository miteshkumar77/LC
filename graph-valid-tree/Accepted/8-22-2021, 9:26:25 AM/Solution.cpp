// https://leetcode.com/problems/graph-valid-tree

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int node) {
        if (parent[node] == -1) return node;
        parent[node] = find(parent[node]);
        return parent[node];
    }
    
    bool onion(int a, int b) {
        int pa = find(a); int pb = find(b);
        if (pa == pb) return false;
        if (rank[pa] == rank[pb]) {
            parent[pa] = pb;
            rank[pb] = rank[pa] + 1;
            return true;
        }
        if (rank[pa] < rank[pb]) {
            swap(pa, pb);
        }
        parent[pa] = pb;
        return true;
    }


    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
        for (auto e : edges) {
            if (!onion(e[0], e[1])) return false;
        }
        return true;
    }
};