// https://leetcode.com/problems/insert-into-a-binary-search-tree

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        TreeNode* tmp = root;
        TreeNode* prev = nullptr;
        while(root) {
            prev = root;
            if (root -> val < val) {
                root = root -> right;
            } else {
                root = root -> left;
            }
        }
        if (prev -> val > val) {
            prev -> left = new TreeNode(val);
        } else {
            prev -> right = new TreeNode(val);
        }
        return tmp;
    }
};