// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

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
    int pseudoPalindromicPaths (TreeNode* root) {
        array<int, 10> ct;
        fill(ct.begin(), ct.end(), 0);
        
        function<int(TreeNode*,int)> helper = [&](TreeNode* node, int numOdd) -> int {
            if (!node) {
                return 0;
            }
            
            ++ct[node->val];
            if (ct[node->val] % 2 == 0) {
                --numOdd;
            } else {
                ++numOdd;
            }
            if (!node->left && !node->right) {
                return numOdd == 0 || numOdd == 1;
            }
            return helper(node->left, numOdd) + helper(node->right, numOdd);
        };
        
        return helper(root, 0);
        
    }
};