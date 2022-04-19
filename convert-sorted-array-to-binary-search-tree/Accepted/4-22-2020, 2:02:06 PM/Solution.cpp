// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedHelper(nums, 0, nums.size() - 1); 
    }
    
    TreeNode* sortedHelper(vector<int>& nums, int L, int R) {
        if (L > R) {
            return nullptr; 
        }
        
        int mid = L + (R - L)/2; 
        TreeNode* root = new TreeNode(nums[mid]); 
        root -> left = sortedHelper(nums, L, mid - 1); 
        root -> right = sortedHelper(nums, mid + 1, R); 
        return root; 
    }
};