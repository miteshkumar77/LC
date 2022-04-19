// https://leetcode.com/problems/merge-two-binary-trees

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return nullptr;
        }
        
        int val = 0; 
        
        if (t1) {
            val = t1 -> val; 
        }
        
        if (t2) {
            val += t2 -> val;
        }
        
        TreeNode* t_n = new TreeNode(val);
        
        t_n -> left = mergeTrees((t1 == nullptr)?nullptr:t1 -> left, (t2 == nullptr)?nullptr:t2 -> left);
        t_n -> right = mergeTrees((t1 == nullptr)?nullptr:t1 -> right, (t2 == nullptr)?nullptr:t2 -> right);
        
        return t_n; 
        
    }
};