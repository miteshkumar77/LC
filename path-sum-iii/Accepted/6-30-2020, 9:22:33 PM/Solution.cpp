// https://leetcode.com/problems/path-sum-iii

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
    int pathSum(TreeNode* root, int sum) {
        
        int ans = 0; 
        unordered_map<int, int> pref; 
        pref[0] = 1; 
        helper(root, sum, ans, 0, pref); 
        return ans; 
    }
    
    
    void helper(TreeNode* root, int& target, int& ans, int curr_sum, unordered_map<int, int>& pref) {
        if (!root) {
            return; 
        }
        
        int acc = curr_sum + root -> val; 
        
        if (pref.find(acc - target) != pref.end()) {
            ans += pref[acc - target]; 
        }
        
        ++pref[acc]; 
        
        helper(root -> left, target, ans, acc, pref); 
        helper(root -> right, target, ans, acc, pref); 
        if (--pref[acc] == 0) {
            pref.erase(acc); 
        }
    }
    
    
    
};