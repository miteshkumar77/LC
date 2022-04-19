// https://leetcode.com/problems/increasing-order-search-tree

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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = nullptr;
        TreeNode* curr = nullptr;
        
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root -> left; 
            } else {
                root = stk.top(); 
                stk.pop(); 
                TreeNode* tmp = root -> right;
                root -> left = nullptr;
                root -> right = nullptr;
                if (curr) {
                    curr -> right = root;
                } else {
                    head = root;
                }
                curr = root;
                root = tmp;
            }
        }
        
        return head;
    }
};