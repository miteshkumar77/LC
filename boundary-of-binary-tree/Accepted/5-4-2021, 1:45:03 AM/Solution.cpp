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
    vector<int> lefts;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        dfs(root, true, true, true);
        //lefts.reserve(lefts.size() + rights.size() + leafs.size());
        //reverse(rights.begin(), rights.end());
        //for (int i : leafs) lefts.push_back(i);
        //for (int i : rights) lefts.push_back(i);
        return lefts;
    }
    
    void dfs(TreeNode* root, bool isRoot, bool left, bool right) {
        if (!root) return;
        if (isRoot) {
            lefts.push_back(root->val);
        }
        if (!isRoot && !root->left && !root->right) {
            lefts.push_back(root->val);
            return;
        }
        if (isRoot && !root->left) left = false;
        if (isRoot && !root->right) right = false;
        if (!isRoot) {
            if (left) {
                lefts.push_back(root->val);
            } 
        }
        dfs(root -> left, false, left, root -> right ? false : right);
        dfs(root -> right, false, root -> left ? false : left, right);
        if (!isRoot) {
            if (!left && right) {
                lefts.push_back(root->val);
            }
        }
    }
};