// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; 
        unordered_map<int, vector<int>> buckets; 
        int minc = 0; 
        int maxc = 0; 
        function<void(TreeNode*,int)> dfs = [&](TreeNode* root, int c) {
            
            if (!root) {
                return; 
            }
            minc = min(minc, c); 
            maxc = max(maxc, c); 
            buckets[c].push_back(root -> val); 
            dfs(root -> left, c - 1); 
            dfs(root -> right, c + 1); 
        };
        dfs(root, 0); 
        for (int i = minc; i <= maxc; ++i) {
            ans.push_back(buckets[i]); 
        }
        return ans; 
        
    }
};