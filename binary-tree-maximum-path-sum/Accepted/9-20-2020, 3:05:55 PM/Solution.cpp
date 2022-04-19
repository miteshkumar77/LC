// https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN; 
        function<int(TreeNode*)> helper = [&](TreeNode* r) -> int {
            if (!r) {
                return 0; 
            }    
            
            int rv = r -> val; 
            int sr = max(helper(r -> right), 0); 
            int sl = max(helper(r -> left), 0);
            ans = max(ans, sr + sl + rv); 
            
            
            return max(sr, sl) + rv; 
            
        };
        helper(root);
        return ans; 
    }
};