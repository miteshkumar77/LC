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


typedef pair<TreeNode*, int> pli; 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans; 
        if (!root) {
            return ans; 
        }
        queue<pli> q; q.push(pli(root, 0));  
        while(!q.empty()) {
            pli top = q.front(); q.pop(); 
            if (top.second + 1 > ans.size()) {
                ans.push_back(vector<int>()); 
            }
            ans[top.second].push_back(top.first -> val); 
            if (top.first -> left) {
                q.push(pli(top.first -> left, top.second + 1)); 
            }
            if (top.first -> right) {
                q.push(pli(top.first -> right, top.second + 1)); 
            }
        }
        return ans; 
    }
};