// https://leetcode.com/problems/diameter-of-binary-tree

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
    
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0; 
        diameterOfBinaryTreeh(root, mx); 
        return mx; 
    }
    int diameterOfBinaryTreeh(TreeNode* root, int& mx) {
        int mn = 0; 
        
        int retl = 0;
        int retr = 0; 
        
        if (root -> left) {
            retl = diameterOfBinaryTreeh(root -> left, mx) + 1; 
            
        }
        
        if (root -> right) {
            retr = diameterOfBinaryTreeh(root -> right, mx) + 1; 
        }
        
        int comp = retl + retr; 
        
        if (comp > mx) {
            mx = comp; 
        }
        return max(retl , retr); 
        
    }
};