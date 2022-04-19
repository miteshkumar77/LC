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
        int ans = INT_MIN;
        helper(root, ans); 
        return ans; 
    }
    
    
    int helper(TreeNode* root, int& ans) {
        if (!root) {
            return 0; 
        }
        
        int left = max(helper(root -> left, ans), 0); 
        int right = max(helper(root -> right, ans), 0); 
        
        if (left + root -> val + right > ans) {
            ans = left + root -> val + right; 
        }
        
        return max(left, right) + root -> val; 
    }
};