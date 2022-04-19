// https://leetcode.com/problems/convert-bst-to-greater-tree

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
    
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* head = root;
        int prev = 0;
        stack<TreeNode*> stk;
        while(root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root -> right;
            } else {
                root = stk.top();
                stk.pop();
                root -> val += prev;
                prev = root -> val;
                root = root -> left;
            }
        }
        return head;
    }
};