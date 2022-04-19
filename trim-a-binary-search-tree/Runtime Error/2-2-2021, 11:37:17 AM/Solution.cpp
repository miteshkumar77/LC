// https://leetcode.com/problems/trim-a-binary-search-tree

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
    void deleteTree(TreeNode* root) {
        if (!root) return;
        deleteTree(root -> left);
        deleteTree(root -> right); 
        delete root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        
        if (root -> val < low) {
            TreeNode* r = root -> right;
            root -> right = nullptr;
            deleteTree(root);
            return trimBST(r, low, high); 
        } else if (root -> val > high) {
            TreeNode * l = root -> left;
            root -> left = nullptr;
            deleteTree(root);
            return trimBST(l, low, high);
        }
        root -> left = trimBST(root -> left, low, high);
        root -> right = trimBST(root -> right, low, high);
        return root;
    }
};