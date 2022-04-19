// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0; 
        int tmp = 0; 
        function<void(TreeNode*)> bt = [&](TreeNode* root) -> void {
            if (!root) {
                return;
            }
            tmp <<= 1; 
            tmp |= root -> val; 
            bt(root -> left); 
            bt(root -> right); 
            if (!root -> left && !root -> right) {
                ans += tmp; 
            }
            tmp >>= 1; 
        };
        bt(root); 
        return ans; 
    }
};