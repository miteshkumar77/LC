// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        return helperV(root, nullptr, nullptr); 
    }
    
    bool helperV(TreeNode* root, TreeNode* max, TreeNode* min) {
        if (!root) {
            return true; 
        }
        
        if (max && root -> val >= max -> val) {
            return false; 
        }
        
        if (min && root -> val <= min -> val) {
            return false; 
        }
        
        return helperV(root -> right, max, root) &&
            helperV(root -> left, root, min); 
    }
};