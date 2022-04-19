// https://leetcode.com/problems/maximum-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recurse(nums, 0, nums.size() - 1); 
    }
    
    
    TreeNode* recurse(vector<int>& nums, int L, int R) {
        if (L > R) {
            return nullptr; 
        }
        
        int mid = max_i(nums, L, R); 
        
        TreeNode* root = new TreeNode(nums[mid]); 
        
        root -> right = recurse(nums, mid+1, R); 
        root -> left = recurse(nums, L, mid - 1); 
        return root; 
    }
    
    
    int max_i(vector<int>& nums, int L, int R) {
        int m = R; 
        for (int i = L; i < R; ++i) {
            if (nums[i] > nums[m]) {
                m = i; 
            }
        }
        
        return m; 
    }
};