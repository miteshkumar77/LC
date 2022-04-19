// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) {
            return nullptr;
        }
        
        if (target == original) return cloned;
        
        TreeNode* lr = getTargetCopy(original->left, cloned->left, target);
        TreeNode* rr = getTargetCopy(original->right, cloned->right, target);
        if (lr) return lr;
        return rr;
    }
};