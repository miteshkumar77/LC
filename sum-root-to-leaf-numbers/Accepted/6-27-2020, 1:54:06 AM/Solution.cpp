// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    int sumNumbers(TreeNode* root) {
        return sums(root, ""); 
    }
    
    
    int sums(TreeNode* root, string s) {
        if (!root) {
            return 0; 
        }
        if (!root -> left && !root -> right) {
            
            
            return stoi(s + to_string(root -> val)); 
        }
        
        return sums(root -> left, s + to_string(root -> val)) + 
            sums(root -> right, s + to_string(root -> val)); 
    }
};