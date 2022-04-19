// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        
        
        if (!root) {
            return vector<int>(); 
        }
        stack<TreeNode*> stak; 
        vector<int> res; res.reserve(100000); 
        
        stak.push(root); 
        
        while(!stak.empty()) {
            res.push_back(stak.top() -> val);
            root = stak.top(); 
            stak.pop(); 
            if (root -> right) {
                stak.push(root -> right); 
            }
            
            if (root -> left) {
                stak.push(root -> left); 
            }
        }
        
        return res; 
        
    }
};