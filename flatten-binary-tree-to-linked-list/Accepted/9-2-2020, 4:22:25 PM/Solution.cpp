// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void flatten(TreeNode* root) {
        if (!root) {
            return; 
        }
        TreeNode* prev = nullptr; 
        stack<TreeNode*> stk; 
        stk.push(root); 
        while(!stk.empty()) {
            TreeNode* nxt = stk.top(); stk.pop(); 
            if (prev) {
                prev -> right = nxt; 
            }
            prev = nxt; 
            if (nxt -> right) {
                stk.push(nxt -> right); 
            }
            if (nxt -> left) {
                stk.push(nxt -> left); 
            }
            nxt -> left = nullptr; 
        }
    }
    
    
    
    
    
    
    
    
};