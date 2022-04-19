// https://leetcode.com/problems/distribute-coins-in-binary-tree

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
    
    
    int helper(TreeNode* root, int& ans) {
        if (!root) return 0;
        root -> val -= helper(root -> left, ans) + helper(root -> right, ans);
        
        ans += abs(root -> val - 1);
        return 1 - root -> val;
    }
    
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};