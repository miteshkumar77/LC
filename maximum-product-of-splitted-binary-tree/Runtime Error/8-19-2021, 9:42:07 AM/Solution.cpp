// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    int sum(TreeNode* root) {
        return root ? root->val + sum(root->left) + sum(root->right) : 0;
    }
    
    int solve(TreeNode* root, int& ans, int sum) {
        if (!root) return 0;
        int r = root->val + solve(root->left, ans, sum) + solve(root->right, ans, sum);
        ans = max(ans, (sum-r) * r);
        return r;
    }    
    int maxProduct(TreeNode* root) {
        int ans = 0;
        solve(root, ans, sum(root));
        return ans;
    }
};