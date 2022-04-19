// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    array<TreeNode*, 3> lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return {nullptr, nullptr, nullptr};
        array<TreeNode*, 3> a{nullptr, nullptr, nullptr};
        if (root == p) {
            a[1] = p;
        }
        if (root == q) {
            a[2] = q;
        }
        if (root->val > p->val) {
            auto rl = lca(root->left, p, q);
            a[0] = rl[0] ? rl[0] : a[0];
            a[1] = rl[1] ? rl[1] : a[1];
            a[2] = rl[2] ? rl[2] : a[2];
        }
        if (root->val < q->val) {
            auto rl = lca(root->right, p, q);
            a[0] = rl[0] ? rl[0] : a[0];
            a[1] = rl[1] ? rl[1] : a[1];
            a[2] = rl[2] ? rl[2] : a[2];
        }
        if (!a[0] && a[1] && a[2]) a[0] = root;
        return a;
    }
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            swap(p, q);
        }
        return lca(root, p, q)[0];
    }
};