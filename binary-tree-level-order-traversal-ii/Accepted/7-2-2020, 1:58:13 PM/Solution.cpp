// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        list<TreeNode*> start; 
        if (root)  {
            start.push_back(root); 
        }
        vector<vector<int> > ans; 
        helper(ans, start); 
        return ans; 
    }
    
    
    void helper(vector<vector<int>>& ans, list<TreeNode*>& level) {
        if (level.size() == 0) {
            return; 
        }
        vector<int> lvl; lvl.reserve(level.size()); 
        list<TreeNode*> next; 
        for (TreeNode* root : level) {
            lvl.push_back(root -> val); 
            if (root -> left) {
                next.push_back(root -> left); 
            }
            if (root -> right) {
                next.push_back(root -> right); 
            }
        }
        
        helper(ans, next); 
        ans.push_back(lvl); 
    }
};