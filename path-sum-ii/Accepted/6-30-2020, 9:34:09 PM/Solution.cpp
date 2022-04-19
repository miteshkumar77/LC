// https://leetcode.com/problems/path-sum-ii

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> path; 
        helper(root, ans, path, 0, sum); 
        return ans; 
    }
    
    
    void helper(TreeNode* root, vector<vector<int> >& ans, vector<int>& path, int acc, int& sum) {
        if (!root) {
            return; 
        }
        
        path.push_back(root -> val); 
        int next = acc + root -> val; 
        if (!root -> left && !root -> right && next == sum) {
            ans.push_back(path); 
        }
        
        
        helper(root -> left, ans, path, next, sum); 
        helper(root -> right, ans, path, next, sum); 
        path.pop_back(); 
        
        
    }
};