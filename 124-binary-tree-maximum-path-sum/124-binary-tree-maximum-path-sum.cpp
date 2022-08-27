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
    array<int, 2> ans(TreeNode* root) {
        if (!root) return {0, -1000000000};
        auto al = ans(root->left);
        auto ar = ans(root->right);
        array<int, 2> a;
        a[0] = max(max(al[0], ar[0]) + root->val, root->val);
        a[1] = max(al[1], max(ar[1], max(al[0] + ar[0] + root->val, a[0])));
        return a;
    }
    int maxPathSum(TreeNode* root) {
        return ans(root)[1];
    }
};