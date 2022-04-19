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
        function<TreeNode*(TreeNode*)> helper = [&] (TreeNode* r) -> TreeNode* {
            if (!r) {
                return nullptr; 
            }
            
            if (r -> val < p -> val && r -> val < q -> val) {
                return helper(r -> right); 
            } else if (r -> val > p -> val && r -> val > q -> val) {
                return helper(r -> left); 
            } else {
                return r; 
            }
        }; 
        return helper(root); 
        
    }
    
    
    
};