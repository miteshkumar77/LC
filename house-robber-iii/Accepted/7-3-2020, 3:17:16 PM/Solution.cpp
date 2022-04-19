// https://leetcode.com/problems/house-robber-iii

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
    int rob(TreeNode* root) {
        pair<int, int> result = helper(root); 
        return max(result.first, result.second); 
    }
    
    
    pair<int, int> helper(TreeNode* root) {
        if (!root) {
            return pair<int, int>(0, 0); 
        }
        
        pair<int, int> lr = helper(root -> left); 
        pair<int, int> rr = helper(root -> right); 
        
        int include_node = root -> val + lr.second + rr.second; 
        int exclude_node = max(lr.second, lr.first) + max(rr.second, rr.first); 
        return pair<int, int>(include_node, exclude_node); 
    }
};