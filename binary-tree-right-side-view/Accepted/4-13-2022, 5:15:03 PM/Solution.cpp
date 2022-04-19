// https://leetcode.com/problems/binary-tree-right-side-view

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
    void helper(TreeNode* root, int depth, vector<int>& ans) {
        if (!root) return;
        helper(root->left, depth+1, ans);
        helper(root->right, depth+1, ans);
        if (depth >= ans.size()) ans.resize(depth+1);
        ans[depth] = root->val;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }
};