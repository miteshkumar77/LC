// https://leetcode.com/problems/increasing-order-search-tree

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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* h{nullptr};
        TreeNode* t{nullptr};
        stack<TreeNode*> stk;
        while(!stk.empty() || root) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top(); stk.pop();
                auto tmp = root->right;
                root->left = nullptr;
                root->right = nullptr;
                if (!h) {
                    h = root;
                    t = root;
                } else {
                    t->right = root;
                    t = root;
                }
                root = tmp;
            }
        }
        return h;
    }
};