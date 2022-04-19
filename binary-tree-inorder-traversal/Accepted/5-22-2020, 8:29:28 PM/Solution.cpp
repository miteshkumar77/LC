// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; res.reserve(100000); 
        stack<TreeNode*> stak; 
        
        while(root || !stak.empty()) {
            if (root) {
                stak.push(root); 
                root = root -> left; 
            } else {
                res.push_back(stak.top() -> val); 
                root = stak.top() -> right; 
                stak.pop(); 
            }
        }
        
        return res; 
    }
};