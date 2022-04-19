// https://leetcode.com/problems/boundary-of-binary-tree

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
    vector<int> ans;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        dfs(root, true, true);
        return ans;
    }
    
    void dfs(TreeNode* root, bool left, bool right) {
        if (!root) return;
        if (left) ans.push_back(root->val);
        if (!(root -> left || root -> right)) {
            if (!(left || right)) ans.push_back(root -> val);
        }
        dfs(root -> left, left, root -> right ? false : right);
        dfs(root -> right, root -> left ? false : left, right);
        if (left) return;
        if (right) ans.push_back(root -> val);
    }
};