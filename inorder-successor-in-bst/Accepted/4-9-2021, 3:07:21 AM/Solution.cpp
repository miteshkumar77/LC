// https://leetcode.com/problems/inorder-successor-in-bst

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
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* prev = nullptr;
        while(root) {
            if (root -> val <= p -> val) {
                root = root -> right;
            } else {
                prev = root;
                root = root -> left;
            }
        }
        return prev;
    }
};