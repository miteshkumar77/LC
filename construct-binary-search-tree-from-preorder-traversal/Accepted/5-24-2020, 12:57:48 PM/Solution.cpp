// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) {
            return nullptr; 
        }
        
        TreeNode* root = new TreeNode(preorder[0]); 
        helper(root, nullptr, preorder, 1); 
        return root; 
    }
    
    int helper(TreeNode* root, TreeNode* max, vector<int>& preorder, int i) {
        if (i == preorder.size()) {
            return -1; 
        }
        
        if (preorder[i] < root -> val) {
            root -> left = new TreeNode(preorder[i]); 
            int res = helper(root -> left, root, preorder, i + 1); 
            if (res != -1) {
                return helper(root, max, preorder, res); 
            } else {
                return -1; 
            }
        } else if (preorder[i] > root -> val && ((!max) || max -> val > preorder[i])) {
            root -> right = new TreeNode(preorder[i]); 
            return helper(root -> right, max, preorder, i + 1); 
        } else {
            return i; 
        }
    }
    
    
    
    
};