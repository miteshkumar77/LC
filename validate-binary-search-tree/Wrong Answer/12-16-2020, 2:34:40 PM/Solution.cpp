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
        int prev = INT_MIN;
        bool ans = true;
        while(curr) {
            if (!(curr -> left)) {
                
                if (curr -> val <= prev) {
                    ans = false;
                }
                prev = curr -> val;
                prev = curr -> val;
                curr = curr -> right;
            } else {
                temp = curr -> left;
                while(temp -> right && temp -> right != curr) {
                    temp = temp -> right;
                }
                if (temp -> right == curr) {
                    temp -> right = nullptr;
                    if (curr -> val <= prev) {
                        ans = false;
                    }
                    prev = curr -> val;
                    prev = curr -> val;
                    curr = curr -> right;

                } else {
                    temp -> right = curr;
                    curr = curr -> left;
                }
            }
        }
        return ans;
    }
};