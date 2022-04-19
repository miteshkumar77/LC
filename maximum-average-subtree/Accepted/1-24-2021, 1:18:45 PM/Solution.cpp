// https://leetcode.com/problems/maximum-average-subtree

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
    pair<int,int> helper(TreeNode* root, double& ans) {
        if (!root) {
            return {0, 0};
        }
        auto l = helper(root -> left, ans);
        auto r = helper(root -> right, ans);
        pair<int, int> c{l.first + r.first + root -> val,  l.second + r.second + 1};
        ans = max(ans, (double)c.first/c.second); 
        return c;
    }
    double maximumAverageSubtree(TreeNode* root) {
        double ret = 0;
        helper(root, ret);
        return ret;
    }
};