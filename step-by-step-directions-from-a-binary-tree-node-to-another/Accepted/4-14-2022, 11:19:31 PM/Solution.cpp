// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

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
    array<bool, 2> solve(TreeNode* root, int a, int b, string& u, string& d) {
        if (!root) return {false, false};
        auto lr = solve(root->left, a, b, u, d);
        auto rr = solve(root->right, a, b, u, d);
        if (lr[0] && lr[1]) return lr;
        if (rr[0] && rr[1]) return rr;
        if (rr[1]) d.push_back('R');
        if (lr[1]) d.push_back('L');
        if (rr[0] || lr[0]) u.push_back('U');
        return {lr[0] || rr[0] || (root->val == a), lr[1] || rr[1] || (root->val == b)};
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string u, d;
        solve(root, startValue, destValue, u, d);
        reverse(d.begin(), d.end());
        return u + d;
    }
};