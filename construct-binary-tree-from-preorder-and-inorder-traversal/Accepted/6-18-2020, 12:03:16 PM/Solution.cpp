// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr; 
        }
        unordered_map <int, int> idx; 
        for (int i = 0; i < inorder.size(); ++i) {
            idx[inorder[i]] = i; 
        }
        TreeNode* root = new TreeNode(preorder[0]); 
        builder(root, nullptr, preorder, 1, idx);
        return root; 
    }
    
    int builder(TreeNode* root, TreeNode* max, vector<int>& preorder, int i, unordered_map<int, int>& idx) {
        if (i >= preorder.size()) {
            return -1; 
        }
        
        int res = -1; 
        
        if (idx[preorder[i]] < idx[root -> val]) {
            root -> left = new TreeNode(preorder[i]); 
            res = builder(root -> left, root, preorder, i + 1, idx); 
        } else if (!max || idx[preorder[i]] < idx[max -> val]) {
            root -> right = new TreeNode(preorder[i]); 
            res = builder(root -> right, max, preorder, i + 1, idx); 
        } else {
            return i; 
        }
        
        if (res != -1) {
            if (!max || idx[preorder[res]] < idx[max -> val]) {
                root -> right = new TreeNode(preorder[res]); 
                res = builder(root -> right, max, preorder, res + 1, idx); 
            }
        }
        
        return res; 
        
    }
};