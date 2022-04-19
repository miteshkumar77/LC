// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* temp = nullptr;
        TreeNode* prev = nullptr;
        
        while(curr) {
            if (!(curr -> left)) {
                if (prev && prev -> val >= curr -> val) return false;
                prev = curr;
                curr = curr -> right;
            } else {
                temp = curr -> left;
                while(temp -> right && temp -> right != curr) {
                    temp = temp -> right;
                }
                if (temp -> right == curr) {
                    temp -> right = nullptr;
                    curr = curr -> right;
                } else {
                    temp -> right = curr;
                    curr = curr -> left;
                }
            }
        }
        return true;
    }
};