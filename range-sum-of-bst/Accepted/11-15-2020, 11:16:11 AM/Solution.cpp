// https://leetcode.com/problems/range-sum-of-bst

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int rval = root -> val;
        int ans = 0; 
        if (rval > low) ans += rangeSumBST(root -> left, low, high);
        if (rval < high) ans += rangeSumBST(root -> right, low, high);
        if (rval <= high && rval >= low) ans += rval;
        return ans;
    }
};