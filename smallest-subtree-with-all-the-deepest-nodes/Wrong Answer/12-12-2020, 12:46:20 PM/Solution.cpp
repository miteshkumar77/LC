// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int mdepth = 0;
        
        function<void(TreeNode*,int)> gd = [&](TreeNode* t, int d) -> void {
            if (!t) return;
            
            mdepth = max(mdepth, d);
            gd(t->left, d+1);
            gd(t->right, d+1);
        };
        
        gd(root, 0);
        
        TreeNode* ans = nullptr;
        
        function<int(TreeNode*,int)> a = [&](TreeNode* t, int d) -> int {
            if (!t) return -1;
            int al = a(t->left,d+1);
            int ar = a(t->right,d+1);
            
            if (al == mdepth && ar == mdepth) {
                ans = t;
            }
            
            return max(al, max(ar, d));
        };
        a(root, 0);
        return ans;
    }
};