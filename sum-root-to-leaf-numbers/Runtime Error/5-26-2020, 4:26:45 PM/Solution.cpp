// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0; 
        }
        if (root -> val == 0) {
            return sumNumbers(root -> left) + sumNumbers(root -> right); 
        }
        
        vector<int> mults; 
        return helper(root, mults); 
    }
    
    
    int helper(TreeNode* root, vector<int>& mults) {
        if (!root) {
            return 0; 
        }
        
        if (!root -> left && !root -> right) {
            mults.push_back(10); 
            return root -> val; 
        }
        
        int ans = helper(root -> left, mults) + helper(root -> right, mults); 
        
        for (int i = 0; i < mults.size(); ++i) {
            ans += (root -> val) * mults[i]; 
            mults[i] *= 10; 
        }
        return ans; 
         
    }
};