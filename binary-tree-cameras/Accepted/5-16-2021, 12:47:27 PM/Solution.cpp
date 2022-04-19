// https://leetcode.com/problems/binary-tree-cameras

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
    /*
        dp[0] = min cameras if root has a camera
        dp[1] = min cameras if root does not have a camera and is covered
        dp[2] = min cameras whether root is being watched or not and all children are covered
    */
    array<int, 3> dfs(TreeNode* root) {
        if (!root) return {(int)1e4, 0, 0};
        auto lr = dfs(root->left);
        auto rr = dfs(root->right);
        array<int, 3> s;
        s[0] = min(lr[0], min(lr[1], lr[2])) + min(rr[0], min(rr[1], rr[2])) + 1;
        s[1] = min(lr[0] + rr[1], min(lr[1] + rr[0], lr[0] + rr[0]));
        s[2] = min(lr[0], lr[1]) + min(rr[0], rr[1]);
        return s;
    }
    
    int minCameraCover(TreeNode* root) {
        auto r = dfs(root);
        return min(r[0], r[1]);
    }
};