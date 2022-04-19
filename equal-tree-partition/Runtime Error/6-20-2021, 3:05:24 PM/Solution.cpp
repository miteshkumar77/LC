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
    
    bool check(TreeNode* root, int sum) {
        sum += root->val;
        if (sum * 2 == T) return true;
        return check(root->left, sum) || check(root->right, sum);
    }
    
    bool checkEqualTree(TreeNode* root) {
        T = total(root);
        if (!root->left && !root->right) return false;
        return check(root, 0);
    }
};