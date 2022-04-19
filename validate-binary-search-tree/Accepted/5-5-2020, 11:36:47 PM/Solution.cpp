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
        return helperV(root, LLONG_MIN, LLONG_MAX); 
    }
    
    bool helperV(TreeNode* root, long long int min, long long int max) {
        if (!root) {
            return true; 
        }
        
        if ((long long int)(root -> val) >= max || (long long int)(root -> val) <= min) {
            return false; 
        }
        
        return helperV(root -> left, min, root -> val) &&
            helperV(root -> right, root -> val, max); 
    }
};