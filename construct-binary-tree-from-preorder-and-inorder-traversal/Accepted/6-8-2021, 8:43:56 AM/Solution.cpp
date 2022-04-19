// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        for (int i = 0; i < n; ++i) mp[inorder[i]] = i;
        stack<TreeNode*> t;
        TreeNode* root = nullptr;
        for (int i : preorder) {
            TreeNode* tn = new TreeNode(i);
            if (t.empty()) {
                t.push(tn); root = tn;
            } else if (mp[i] < mp[t.top()->val]) {
                t.top()->left = tn;
                t.push(tn);
            } else {
                TreeNode* tmp;
                while(!t.empty() && mp[t.top()->val] < mp[i]) {
                    tmp = t.top();
                    t.pop();
                }
                tmp->right = tn;
                t.push(tn);
            }
        }
        return root;
    }
};