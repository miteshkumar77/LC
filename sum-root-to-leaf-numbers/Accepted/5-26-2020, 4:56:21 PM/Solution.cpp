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
        
        int ans = 0; 
        helper(root, ans); 
        return ans; 
    }
    
    
    list<unsigned long long int> helper(TreeNode* root, int& ans) {
        if (!root -> left && !root -> right) {
            ans += root -> val; 
            return list<unsigned long long int>{10}; 
        }
        
        list <unsigned long long int> result; 
        if (root -> left) {
            list<unsigned long long int> left_result = helper(root -> left, ans); 
            result.splice(result.end(), left_result);
        }
        
        if (root -> right) {
            list<unsigned long long int> right_result = helper(root -> right, ans); 
            result.splice(result.end(), right_result); 
        }
        
        for (auto iter = result.begin(); iter != result.end(); ++iter) {
            ans += (*iter) * (root -> val); 
            (*iter)*= 10; 
        }
        
        return result; 
    }
};