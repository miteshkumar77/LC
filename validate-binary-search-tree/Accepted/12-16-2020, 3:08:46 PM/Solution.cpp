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
        bool ans = true;
        while(curr) {
            if (!(curr -> left)) {
                
                if (prev && curr -> val <= prev -> val) {
                    ans = false;
                }
                prev = curr;
                curr = curr -> right;
            } else {
                temp = curr -> left;
                while(temp -> right && temp -> right != curr) {
                    temp = temp -> right;
                }
                if (temp -> right == curr) {
                    temp -> right = nullptr;
                    if (prev && curr -> val <= prev -> val) {
                        ans = false;
                    }
                    prev = curr;
                    curr = curr -> right;

                } else if (ans) { // Do not need to continue traversing 
                                  // if we already found a violation
                    temp -> right = curr;
                    curr = curr -> left;
                } else { // Keep going right until all of the remaining added right childs are 
                         // removed
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};