// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int maxDepth(TreeNode* root) {
        return maxDepth(root, 0);
    }
    
    int maxDepth(TreeNode* root, int i) {
        if (!root) {
            return i;
        }
        
        return max(maxDepth(root -> left, i + 1), maxDepth(root -> right, i + 1)); 
    }
    
};