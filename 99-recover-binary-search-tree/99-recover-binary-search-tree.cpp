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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* prev{nullptr};
        TreeNode* curr{root};
        while(curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                curr = stk.top();
                stk.pop();
                if (prev && prev->val > curr->val) {
                    swap(prev->val, curr->val);
                }
                prev = curr;
                curr = curr->right;
            }
        }
        
        curr = root;
        prev = nullptr;
        while(curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->right;
            } else {
                curr = stk.top();
                stk.pop();
                if (prev && prev->val < curr->val) {
                    swap(prev->val, curr->val);
                }
                prev = curr;
                curr = curr->left;
            }
        }
    }
};