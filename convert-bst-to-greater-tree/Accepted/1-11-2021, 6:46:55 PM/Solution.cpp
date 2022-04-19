// https://leetcode.com/problems/convert-bst-to-greater-tree

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
    void builder(TreeNode* root, int& prev) {
        if (!root) return;
        builder(root -> right, prev);
        root -> val += prev;
        prev = root -> val;
        builder(root -> left, prev);
    }
    TreeNode* convertBST(TreeNode* root) {
        int prv = 0;
        builder(root, prv);
        return root;
    }
};