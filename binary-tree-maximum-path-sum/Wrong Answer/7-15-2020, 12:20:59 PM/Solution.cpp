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
    typedef pair<int, int> pii; 
    int maxPathSum(TreeNode* root) {
        int ans = 0; 
        helper(root, ans); 
        return ans; 
    }
    
    int helper(TreeNode* root, int& ans) {
        if (!root) {
            return 0; 
        }
        
        int lR = helper(root -> left, ans); 
        int rR = helper(root -> right, ans); 
        ans = max(ans, lR + rR + root -> val); 
        return max(lR, rR) + root -> val; 
    }
};