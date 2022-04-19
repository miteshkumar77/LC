// https://leetcode.com/problems/inorder-successor-in-bst

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* curr = root;
        stack<TreeNode*> stk;
        TreeNode* met = nullptr;
        while(root || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr -> left;
            } else {
                curr = stk.top();
                stk.pop();
                if (curr == p) {
                    met = p;
                } else if (met) {
                    return curr;
                }
                curr = curr -> right;
            }
        }
        return nullptr;
    }
};