// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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


// [8, 5, 1]

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        stack<TreeNode*> stk;
        stk.push(new TreeNode(preorder[0]));
        TreeNode* root = stk.top();
        for (int i = 1; i < preorder.size(); ++i) {
            if (stk.top() -> val > preorder[i]) {
                stk.top() -> left = new TreeNode(preorder[i]);
                stk.push(stk.top() -> left);
            } else {
                TreeNode* tmp = nullptr;
                while(!stk.empty() && stk.top() -> val < preorder[i]) {
                    tmp = stk.top();
                    stk.pop();
                }
                tmp -> right = new TreeNode(preorder[i]);
                stk.push(tmp -> right);
            }
        }
        return root;
    }
};