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
        int ans = -1; 
        kth(root, smack, ans); 
        return ans; 
    }
    
    void kth(TreeNode* root, int& k, int& ans) {
        if (!root) {
            return; 
        }
        
        kth(root -> left, k, ans); 
        --k; 
        if (k == 0) {
            ans = root -> val; 
            return; 
        }
        kth(root -> right, k, ans); 
    }
};