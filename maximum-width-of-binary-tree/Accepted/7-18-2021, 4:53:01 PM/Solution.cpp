// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    typedef unsigned long long ull;
    int widthOfBinaryTree(TreeNode* root) {
        ull ans = 0;
        vector<pair<TreeNode*, ull>> lvl;
        if (root) lvl.push_back({root, 0});
        while(!lvl.empty()) {
            ans = max(ans, lvl.back().second - lvl[0].second + 1);
            decltype(lvl) nxt;
            for (auto p : lvl) {
                if (p.first->left) {
                    nxt.push_back({p.first->left, p.second * 2});
                }
                if (p.first->right) {
                    nxt.push_back({p.first->right, p.second * 2 + 1});
                }
            }
            lvl.swap(nxt);
        }
        return ans;
    }
};