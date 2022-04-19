// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    
    void helper(TreeNode* root, int depth, int& ans) {
        if (!root) {
            return;
        }
        
        if (!root -> left && !root -> right) {
            ans = min(ans, depth);
        }
        
        helper(root -> left, depth + 1, ans); 
        helper(root -> right, depth + 1, ans);
    }
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = INT_MAX;
        helper(root, 1, ans);
        return ans;
    }
};