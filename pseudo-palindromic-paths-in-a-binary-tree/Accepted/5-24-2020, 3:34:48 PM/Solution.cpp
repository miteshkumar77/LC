// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

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
    
    array<bool, 10> int_set{false};
    int set_size = 0; 
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if (!root) {
            if (set_size <= 1) {
                return 1; 
            } else {
                return 0; 
            }
        }
        
        if (int_set[root -> val]) {
            int_set[root -> val] = false; 
            --set_size; 
        } else {
            int_set[root -> val] = true; 
            ++set_size; 
        }
        
        int ans = 0; 
        if (root -> left) {
            ans += pseudoPalindromicPaths(root -> left); 
        }
        
        if (root -> right) {
            ans += pseudoPalindromicPaths(root -> right); 
        }
        
        if (!root -> left && !root -> right) {
            ans += pseudoPalindromicPaths(nullptr); 
        }
        
        if (int_set[root -> val]) {
            int_set[root -> val] = false; 
            --set_size; 
        } else {
            int_set[root -> val] = true; 
            ++set_size; 
        }
        
        return ans; 
        
    }
};