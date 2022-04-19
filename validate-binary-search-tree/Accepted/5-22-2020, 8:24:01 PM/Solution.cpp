// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stak; 
        TreeNode* prev = nullptr; 
        TreeNode* head = root; 
        
        
         while(root || !stak.empty()) {
             if (root) {
                 stak.push(root); 
                 root = root -> left; 
             } else {
                 if (prev) {
                     if (stak.top() -> val <= prev -> val) {
                         return false; 
                     }
                 }
                 
                 prev = stak.top(); 
                 root = stak.top() -> right; 
                 stak.pop(); 
             }
         }
        
        return true; 
        
        
    }
    
    
};