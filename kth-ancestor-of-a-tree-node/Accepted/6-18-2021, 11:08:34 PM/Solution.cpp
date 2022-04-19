// https://leetcode.com/problems/kth-ancestor-of-a-tree-node

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) : binParent(n, vector<int>(max_pow)) {
        for (int i = 0; i < n; ++i) {
            binParent[i][0] = parent[i];
        }
        for (int pow = 1; pow < max_pow; ++pow) {
            for (int i = 0; i < n; ++i) {
                if (binParent[i][pow-1] == -1) {
                    binParent[i][pow] = -1;
                } else {
                    binParent[i][pow] = binParent[binParent[i][pow-1]][pow-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
            int p = 1<<(max_pow-1);
            for (int i = max_pow-1; i >= 0; --i, p >>= 1) {
                if (k >= p) {
                    node = binParent[node][i];
                    if (node == -1) return -1;
                    k -= p;
                }
            }
        return node;
    }
    int max_pow = 16;
    vector<vector<int>> binParent;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */