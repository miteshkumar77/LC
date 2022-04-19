// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    int kthSmallest(TreeNode* root, int k) {
        int smack = k; 
        return kth(root, smack); 
    }
    
    int kth(TreeNode* root, int& k) {
        if (root -> left) {
            return kth(root -> left, k);   
        }
        
        --k; 
        if (k == 0) {
            return root -> val; 
        }
        
        if (root -> right) {
            return kth(root -> right, k); 
        }
        return 0; 
    }
};