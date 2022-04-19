// https://leetcode.com/problems/closest-binary-search-tree-value

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

    double ans; 
    bool set = false; 
public:
    int closestValue(TreeNode* root, double target) {
        if (!root) {
            return -1; 
        }
        if (!set || abs(target - root -> val) < abs(target - ans)) {
            ans = root -> val; 
            set = true; 
        }
        
        closestValue(root -> left, target); 
        closestValue(root -> right, target); 
        return ans; 
        
        
    }
};