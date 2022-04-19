// https://leetcode.com/problems/symmetric-tree

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
    bool isSymmetric(TreeNode* root) {
        if (!(root)){
            return true; 
        }
        if ((!(root -> left)) && (!(root -> right))) {
            
            return true;
        }
        if ( (!(root -> left) && (root -> right)) ||
             ((root -> left) && !(root -> right))) {
            
            return false;
        }
        
        return isSymmetric(root -> left) && isSymmetric(root -> right);
    }
};