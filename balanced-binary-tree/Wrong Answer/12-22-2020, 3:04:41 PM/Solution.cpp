// https://leetcode.com/problems/balanced-binary-tree

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
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).first;
    }
    
    pair<bool, int> isBalancedHelper(TreeNode* root) {
        if (!root) {
            return make_pair(true, 0);
        }
        
        auto rl = isBalancedHelper(root -> left);
        auto rr = isBalancedHelper(root-> right);
        
        return make_pair(abs(rl.second - rr.second) <= 1, 
                         max(rl.second, rr.second) + 1); 
    }
};