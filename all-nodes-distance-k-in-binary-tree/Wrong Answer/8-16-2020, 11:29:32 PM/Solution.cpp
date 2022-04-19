// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        vector<int> ans; 
        
        
        function<void(TreeNode*,int)> helper = [&] (TreeNode* r, int depth) -> void {
            
            if (!r) {
                return; 
            }
            
            
            if (depth == 0) {
                ans.push_back(r -> val); 
                return; 
            }
            helper(r->left, depth - 1); helper(r -> right, depth - 1); 
        };
        
        
        function<int(TreeNode*)> solver = [&] (TreeNode* r) -> int {
            if (!r) {
                return -1; 
            }
            
            if (r == target) {
                helper(r, K); 
                return 0; 
            }
            
            int lr = solver(r -> left); 
            int rr = solver(r -> right); 
            
            if (lr >= 0) {
                helper(r -> right, K - lr - 2);
                return lr + 1; 
            }
            
            if (rr >= 0) {
                helper(r -> left, K - rr - 2); 
                return rr + 1; 
            }
            return -1; 
        };
        
        solver(root); 
        return ans; 
    }
    
    
    
};