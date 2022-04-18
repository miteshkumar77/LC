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
    int kthSmallest(TreeNode* root, int k) {
        int smack = k; 
        int ans = -1; 
        bool cont = true; 
        kth(root, smack, ans, cont); 
        return ans; 
    }
    
    void kth(TreeNode* root, int& k, int& ans, bool& cont) {
        if (!root) {
            return; 
        }
        
        if (cont) {
            kth(root -> left, k, ans, cont);    
        }
        
        if (--k == 0) {
            ans = root -> val; 
            cont = false; 
        }
        
        if (cont) {
            kth(root -> right, k, ans, cont); 
        }
    }
};