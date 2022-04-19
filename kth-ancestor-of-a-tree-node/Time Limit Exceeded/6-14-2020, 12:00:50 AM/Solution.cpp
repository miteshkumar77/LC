// https://leetcode.com/problems/kth-ancestor-of-a-tree-node

class TreeAncestor {
public:
    
    vector<int> tree; 
    TreeAncestor(int n, vector<int>& parent) {
        tree = parent; 
    }
    
    int getKthAncestor(int node, int k) {
        int root = node; 
        for (int i = 0; i < k; ++i) {
            if (root == 0) {
                return -1; 
            }
            root = tree[root]; 
        }
        return root; 
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */