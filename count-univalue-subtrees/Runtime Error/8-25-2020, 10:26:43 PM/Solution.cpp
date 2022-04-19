// https://leetcode.com/problems/count-univalue-subtrees

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
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0; 
        
        function<bool(TreeNode*,int)> dfs = [&](TreeNode* r, int parentval) -> bool {
            if (!r) {
                return true; 
            }
            
            bool lr = dfs(r -> left, r -> val); 
            bool rr = dfs(r -> right, r -> val); 
            if (lr && rr) {
                // cout << r -> val << endl; 
                ++ans; 
                return r -> val == parentval; 
            }
            return false; 
        };
        dfs(root, root -> val); 
        return ans; 
    }
};