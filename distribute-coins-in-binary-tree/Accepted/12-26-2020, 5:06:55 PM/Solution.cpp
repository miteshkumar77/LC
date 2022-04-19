// https://leetcode.com/problems/distribute-coins-in-binary-tree

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
    int distributeCoins(TreeNode* root) {
        return helper(root).second;
    }
    
    pair<int,int> helper(TreeNode* root) {
        
        if (!root) {
            return {0, 0};
        }
        
        int dist = root -> val - 1;
        auto pl = helper(root -> left);
        auto pr = helper(root -> right);
        dist += pl.first + pr.first;
        return {dist, 
                abs(dist) + pl.second + pr.second};
    }
    
    
};