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
        unordered_map<int, int> idx; 
        for (int i = 0; i < inorder.size(); ++i) {
            idx[inorder[i]] = i; 
        }
        
        int pre_idx = 0; 
        function<TreeNode*(int,int)> solver = [&](int lo, int hi) -> TreeNode* {
            if (lo > hi) {
                return nullptr; 
            }
            int mid = idx[preorder[pre_idx]]; 
            TreeNode* root = new TreeNode(preorder[pre_idx++]); 
            root -> left = solver(lo, mid - 1);
            root -> right = solver(mid + 1, hi); 
            return root; 
        };
        
        return solver(0, preorder.size() - 1); 
    }
    
    
};