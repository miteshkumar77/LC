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
    void flatten(TreeNode* root) {
        helper(root); 
    }
    
    
    TreeNode* helper(TreeNode* root) {
        if (!root) {
            return nullptr; 
        }
        
        TreeNode* lend = helper(root -> left); 
        TreeNode* rend = helper(root -> right); 
        TreeNode* l = root -> left; 
        TreeNode* r = root -> right; 
        root -> left = nullptr; 
        root -> right = l; 
        if (lend) {
            lend -> right = r; 
        } else {
            root -> right = r; 
        }
        if (!rend) {
            if (!lend) {
                return root; 
            } else {
                return lend; 
            }
        }
        return rend; 
    }
    
    
    
    
    
};