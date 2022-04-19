// https://leetcode.com/problems/unique-binary-search-trees-ii

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
    
    TreeNode* copy_inorder(int& i, TreeNode* r) {
        if (!r) return nullptr;    
        TreeNode* ret = new TreeNode(0);
        ret->left = copy_inorder(i, r->left);
        ret->val = i++;
        ret->right = copy_inorder(i, r->right);
        return ret;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        dp[0].push_back(nullptr);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                int l = j;
                int r = i - 1 - j;
                for (auto nl : dp[l]) {
                    for (auto nr : dp[r]) {
                        TreeNode* tn = new TreeNode(0);
                        tn->left = nl;
                        tn->right = nr;
                        dp[i].push_back(tn);
                    }
                }
            }
        }
        
        vector<TreeNode*> ans; ans.reserve(dp[n].size());
        for (auto r : dp[n]) {
            int idx = 1;
            ans.push_back(copy_inorder(idx, r));
        }
        return ans;
    }
};