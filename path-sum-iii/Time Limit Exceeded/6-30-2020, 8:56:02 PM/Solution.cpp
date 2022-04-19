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
        
        list<int> sums; 
        int ans = 0; 
        helper(root, ans, sums, sum); 
        return ans; 
    }
    
    
    void helper(TreeNode* root, int& ans, list<int> sums, int& sum) {
        if (!root) {
            return; 
        }
        list<int> next; 
        if (root -> val == sum) {
            ++ans; 
        }
        for (int i : sums) {
            next.push_back(i + root -> val); 
            if (next.back() == sum) {
                ++ans; 
            }
        }
        
        next.push_back(root -> val); 
        
        helper(root -> left, ans, next, sum); 
        helper(root -> right, ans, next, sum); 
    }
};