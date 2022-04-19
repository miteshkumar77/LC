// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int cur = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            if (!p.first) continue;
            if (p.second != cur) {
                cur = p.second;
                ans.push_back(vector<int>());
            }
            ans.back().push_back(p.first->val);
            q.push({p.first->left, p.second+1});
            q.push({p.first->right, p.second+1});
        }
        return ans;
    }
};