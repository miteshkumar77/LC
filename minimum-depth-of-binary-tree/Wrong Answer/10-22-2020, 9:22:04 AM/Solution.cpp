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
            ans = max(ans, depth);
        }
        
        helper(root -> left, depth + 1, ans); 
        helper(root -> right, depth + 1, ans);
    }
    int minDepth(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};