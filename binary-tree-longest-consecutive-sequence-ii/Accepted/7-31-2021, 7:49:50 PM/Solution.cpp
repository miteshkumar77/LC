// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii

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
    array<int,2> dfs(TreeNode* root, int& ans) {
        if (!root) return {0,0};
        auto lr = dfs(root->left, ans);
        auto rr = dfs(root->right, ans);
        array<int,2> ret{0,0};
        int left_inc = 0;
        int left_dec = 0;
        int right_inc = 0;
        int right_dec = 0;
        if (root->left) {
            if (root->left->val == root->val - 1) {
                left_inc = lr[0];
            } else if (root->left->val == root->val + 1) {
                left_dec = lr[1];
            }
        }
        if (root->right) {
            if (root->right->val == root->val - 1) {
                right_inc = rr[0];
            } else if (root->right->val == root->val + 1) {
                right_dec = rr[1];
            }
        }
        ans = max(max(ans, left_dec + right_inc + 1), right_dec + left_inc + 1);
        ret[0] = max(right_inc, left_inc) + 1;
        ret[1] = max(right_dec, left_dec) + 1;
        return ret;
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};