// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int maxPathSum(TreeNode* root) {
        int ans = 0; 
        helper(root, ans); 
        return ans; 
    }
    
    
    int helper(TreeNode* root, int& ans) {
        if (!root) {
            return 0; 
        }
        
        int left = helper(root -> left, ans); 
        int right = helper(root -> right, ans); 
        
        if (left + root -> val + right > ans) {
            ans = left + root -> val + right; 
        }
        
        return max(left, right) + root -> val; 
    }
};