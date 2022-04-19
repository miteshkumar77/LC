// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; 
        if (!root) {
            return ans; 
        }
        stack<TreeNode*> stk; 
        TreeNode* cur = root; 
        while(cur || !stk.empty()) {
            if (cur) {
                stk.push(cur); 
                cur = cur -> left; 
            } else {
                ans.push_back(stk.top() -> val); 
                cur = stk.top() -> right; 
                stk.pop(); 
            }
        }
        return ans; 
    }
};