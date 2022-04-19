// https://leetcode.com/problems/path-sum-ii

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
    void calc(TreeNode* root,
              vector<vector<int>>& ans,
              unordered_map<int,unordered_set<int>>& st,
              vector<int>& path, int sum, int target) {
        if (!root) return;
        path.push_back(root->val);
        sum += root->val;
        st[sum].insert(path.size());
        calc(root->left, ans, st, path, sum, target);
        calc(root->right, ans, st, path, sum, target);
        if (!root->left && !root->right) {
            
            if (sum == target) {
                ans.push_back(path);
            }
        }
        st[sum].erase(path.size());
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_map<int, unordered_set<int>> st;
        st[0].insert(0);
        calc(root, ans, st, path, 0, targetSum);
        return ans;
    }
};