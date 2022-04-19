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
    using ll = long long;
    int sum(TreeNode* root) {
        return root ? root->val + sum(root->left) + sum(root->right) : 0;
    }
    
    int solve(TreeNode* root, ll& ans, int sum) {
        if (!root) return 0;
        int r = root->val + solve(root->left, ans, sum) + solve(root->right, ans, sum);
        ans = max(ans, (ll)(sum-r) * (ll)r);
        return r;
    }    
    int maxProduct(TreeNode* root) {
        ll ans = 0;
        ll M = 1e9 + 7;
        solve(root, ans, sum(root));
        return ans%M;
    }
};