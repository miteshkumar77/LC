// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        int L = 0; 
        int R = 0; 
        dfs(root, L, R, 0); 
        return R - L; 
    }
    
    void dfs(TreeNode* root, int& L, int& R, int C) {
        if (!root) {
            return; 
        }
        
        
        if (C < L) {
            L = C; 
        }
        
        if (C > R) {
            R = C; 
        }
        
        dfs(root -> left, L, R, C - 1); 
        dfs(root -> right, L, R, C + 1); 
    }
};