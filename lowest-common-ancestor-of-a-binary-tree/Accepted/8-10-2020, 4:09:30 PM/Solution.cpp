// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr; 
        
        function<int(TreeNode*)> lca = [&] (TreeNode* r) -> int {
            
            if (ans || !r) {
                return 0; 
            }
            
            
            int ansn = 0; 
            if (r == p || r == q) {
                ++ansn; 
            }
            
            ansn += lca(r -> left); 
            ansn += lca(r -> right); 
            
            if (ansn == 2 && !ans) {
                ans = r; 
            }
            return ansn; 
        };
        
        lca(root); 
        return ans; 
    }
};