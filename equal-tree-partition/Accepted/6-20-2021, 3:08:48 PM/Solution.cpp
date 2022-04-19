// https://leetcode.com/problems/equal-tree-partition

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
    int T;
    int total(TreeNode* root) {
        if (!root) return 0;
        return total(root->left) + total(root->right) + root->val;
    }
    
    pair<int,bool> check(TreeNode* root) {
        if (!root) return {0, false};
        auto lr = check(root->left);
        auto rr = check(root->right);
        pair<int, bool> ret = {lr.first + rr.first + root->val, lr.second || rr.second};
        ret.second = ret.second || ret.first * 2 == T;
        return ret;
    }
    
    bool checkEqualTree(TreeNode* root) {
        T = total(root);
        return check(root->left).second || check(root->right).second;
    }
};