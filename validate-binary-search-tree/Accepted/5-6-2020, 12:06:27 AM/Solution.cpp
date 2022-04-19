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
        TreeNode* prev = nullptr; 
        return helper(root, prev); 
    }
    
    bool helper(TreeNode* curr, TreeNode*& prev) {
        if (!curr) {
            return true; 
        }
        
        if (!helper(curr -> left, prev)) {
            return false; 
        }
        
        if (prev && curr -> val <= prev -> val) {
            return false; 
        }
        
        prev = curr; 
        
        return helper(curr -> right, prev); 
    }
};