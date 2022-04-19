// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

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
    int maxAncestorDiff(TreeNode* root) {
        function<int(TreeNode*,int,int)> dfs = [&](TreeNode* node, int lo, int hi) -> int {
            if (!node) return hi - lo;
            
            int nlo = min(lo, node -> val);
            int nhi = max(hi, node -> val);
                        
            return max(max(dfs(node -> left, nlo, nhi), dfs(node -> right, nlo, nhi)), hi - lo);
        };
        
        return dfs(root, root -> val, root -> val);
    }
};