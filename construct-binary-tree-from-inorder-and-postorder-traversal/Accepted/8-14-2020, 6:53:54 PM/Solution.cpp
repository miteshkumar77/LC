// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post_idx = postorder.size() - 1; 
        unordered_map<int, int> idx; 
        for (int i = 0; i < postorder.size(); ++i) {
            idx[inorder[i]] = i; 
        }
        
        function<TreeNode*(int,int)> buildTree = [&](int lo, int hi) -> TreeNode* {
            if (lo > hi) {
                return nullptr; 
            }
            
            int mid = idx[postorder[post_idx]]; 
            TreeNode* root = new TreeNode(postorder[post_idx--]); 
            
            root -> right = buildTree(mid + 1, hi); 
            root -> left = buildTree(lo, mid - 1); 
            return root; 
        };
        
        return buildTree(0, postorder.size() - 1); 
         
    }
};