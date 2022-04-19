// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true; 
        } else {
            return validate_bst_helper(root, 0, 0, false, false);
        }
    }

    
    bool validate_bst_helper(TreeNode* root, int min_left, int max_right, 
                             bool yet_left, bool yet_right) {
        bool r;
        bool l;
        if (root -> left) {
            if (!yet_right) {
                l = (root -> left -> val < root -> val) && 
                validate_bst_helper(root -> left, min_left, root -> val, true, yet_right);
            } else {
                l = (min_left < root -> left -> val < root -> val) &&
                validate_bst_helper(root -> left, min_left, root -> val, yet_left, yet_right);
            }
        } else {
            l = true;
        }

        if (root -> right) {
            if (!yet_left) {
                r = (root -> right -> val > root -> val) && 
                validate_bst_helper(root -> right, root -> val, max_right, yet_left, true);
            } else {
                r = (max_right > root -> right -> val > root -> val) &&
                validate_bst_helper(root -> right, root -> val, max_right, yet_left, yet_right);
            }
        } else {
            r = true;
        }

        return r && l;     
    }
};