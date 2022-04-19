// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    array<TreeNode*, 2> dfs(TreeNode* root) {
        if (!root) return {nullptr, nullptr};
        auto lr = dfs(root->left);
        auto rr = dfs(root->right);
        root->left = nullptr;
        root->right = lr[0];
        if (lr[1]) {
            lr[1] -> right = rr[0];
        } else {
            root->right = rr[0];
        }
        return {root, (!rr[1]) ? root : rr[1]};
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};