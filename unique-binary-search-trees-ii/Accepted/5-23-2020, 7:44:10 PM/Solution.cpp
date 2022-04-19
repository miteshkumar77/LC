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
        vector<vector<vector<TreeNode*> > > dp(n + 2, vector<vector<TreeNode*> >(n + 2, vector<TreeNode*>())); 
        return treeGenerator(1, n, dp); 
    }
    
    vector<TreeNode*> treeGenerator(int L, int R, vector<vector<vector<TreeNode*> > >& dp) {
        
        
        if (dp[L][R].size() != 0) {
            return dp[L][R]; 
        }
        
        if (R < L) {
            dp[L][R].push_back(nullptr);
            return dp[L][R]; 
        }
        if (L == R) {
            dp[L][R].push_back(new TreeNode(L)); 
            return dp[L][R];
        }
        vector<TreeNode*> res; 
        for (int i = L; i <= R; ++i) {
            vector<TreeNode*> left_trees = treeGenerator(L, i - 1, dp); 
            vector<TreeNode*> right_trees = treeGenerator(i + 1, R, dp); 
            
            for (int x = 0; x < left_trees.size(); ++x) {
                for (int j = 0; j < right_trees.size(); ++j) {
                    TreeNode* root = new TreeNode(i); 
                    root -> left = left_trees[x];
                    root -> right = right_trees[j]; 
                    dp[L][R].push_back(root); 
                }
            }
        }
        
        return dp[L][R]; 
    }
    
    TreeNode* cpyTree(TreeNode* root) {
        if (!root) {
            return nullptr; 
        }
        
        TreeNode* newRoot = new TreeNode(root -> val); 
        newRoot -> left = cpyTree(root -> left); 
        newRoot -> right = cpyTree(root -> right); 
        return newRoot; 
    }
};