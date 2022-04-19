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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0}); 
        int prev = -1;
        vector<int> ans;
        pair<TreeNode*, int> top;
        while(!q.empty()) {
            top = q.front(); 
            q.pop();
            if (!top.first) continue;
            q.push({top.first->right, top.second + 1});
            q.push({top.first->left, top.second + 1}); 
            if (top.second != prev) {
                prev = top.second; 
                ans.push_back(top.first->val); 
            }
        }
        
        return ans;
    }
};