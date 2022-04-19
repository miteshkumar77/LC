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
    typedef pair<int, int> pii; 
    int diameterOfBinaryTree(TreeNode* root) {
        return diam(root).second - 1; 
    }
    
    
    pair<int, int> diam(TreeNode* root) {
        if (!root) {
            return pii(0, 0); 
        }
        
        pii rL = diam(root -> left); 
        pii rR = diam(root -> right); 
        return pii(max(rL.first, rR.first) + 1, max(max(rL.first + rR.first + 1, rL.second), rR.second)); 
    }
};