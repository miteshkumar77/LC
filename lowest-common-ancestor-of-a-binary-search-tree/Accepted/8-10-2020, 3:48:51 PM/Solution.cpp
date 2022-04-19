// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

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
        TreeNode* ansn = nullptr;  
        function<int(TreeNode*)> helper = [&] (TreeNode* r) -> int {
            if (ansn || !r) {
                return 0; 
            }
            
            int ans = 0; 
            if (r == p || r == q) {
                ++ans; 
            }
            
            ans += helper(r -> left); 
            ans += helper(r -> right); 
            if (ans == 2 && !ansn) {
                // cout << r -> val << endl; 
                ansn = r; 
            }
            return ans; 
            
            
        };
        helper(root); 
        return ansn; 
        
    }
    
    
    
};