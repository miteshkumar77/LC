// https://leetcode.com/problems/unique-binary-search-trees-ii

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>(); 
        }
        
        vector<vector<TreeNode*> > dp(n + 1, vector<TreeNode*>()); 
        return treeGenerator(n, dp); 
        
        
    }
    
    
    vector<TreeNode*> treeGenerator(int n, vector<vector<TreeNode*> >& dp) {
        
        
        if (n == 0) {
            return vector<TreeNode*>{ nullptr }; 
        }
        
        if (dp[n].size() != 0) {
            return dp[n]; 
        }
        
        if (n == 1) {
            return vector<TreeNode*> { new TreeNode(n) }; 
        }
        
         
        for (int i = 1; i <= n; ++i) {
            vector<TreeNode*> left_trees = treeGenerator(i - 1, dp); 
            vector<TreeNode*> right_trees = treeGenerator(n - i, dp); 
            for (int x = 0; x < left_trees.size(); ++x) {
                for (int j = 0; j < right_trees.size(); ++j) {
                    TreeNode* root = new TreeNode(i); 
                    root -> left = left_trees[x]; 
                    root -> right = cpyTree(right_trees[j], i);
                    dp[n].push_back(root); 
                }
            }
        }
        
        return dp[n]; 
    }
    
    TreeNode* cpyTree(TreeNode* root, int offset) {
        if (!root) {
            return nullptr; 
        }
        
        TreeNode* newRoot = new TreeNode(root -> val + offset); 
        newRoot -> left = cpyTree(root -> left, offset); 
        newRoot -> right = cpyTree(root -> right, offset); 
        return newRoot; 
    }
};