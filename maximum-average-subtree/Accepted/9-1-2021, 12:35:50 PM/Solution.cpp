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
    
    //    avg     total   sz
    tuple<double, double, int> calc(TreeNode* root) {
        if (!root) return {0.0, 0.0, 0};
        auto l = calc(root->left); auto r = calc(root->right);
        int sz = get<2>(l) + get<2>(r) + 1;
        double total = (get<1>(l) + get<1>(r) + root->val);
        double avg = total/(double)sz;
        return {max(get<0>(l), max(get<0>(r), avg)), total, sz};
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        return get<0>(calc(root));
    }
};