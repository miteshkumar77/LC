// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Res {
    
    Res() {
        p = false;
        q = false;
        tn = nullptr;
    }
    
    
    
    bool p;
    bool q;
    TreeNode* tn;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q).tn;
    }
    Res lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return Res();
        auto l = lca(root -> left, p, q);
        if (l.tn) return l;
        auto r = lca(root -> right, p, q);
        if (r.tn) return r;
        
        auto curr = Res();
        curr.p = l.p || r.p || p == root;
        curr.q = l.q || r.q || q == root;
        if (curr.p && curr.q) curr.tn = root; 
        return curr;
    }
};