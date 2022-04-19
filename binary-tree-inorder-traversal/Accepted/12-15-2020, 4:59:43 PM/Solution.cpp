// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        TreeNode* pre;
        while(cur) {
            if (!cur -> left) {
                ans.push_back(cur -> val);
                cur = cur -> right;
            } else {
                pre = cur -> left;
                while(pre -> right) {
                    pre = pre -> right;
                }
                pre -> right = cur;
                TreeNode* temp = cur;
                cur = cur -> left;
                temp -> left = nullptr;
            }
        }
        
        return ans;
    }
};