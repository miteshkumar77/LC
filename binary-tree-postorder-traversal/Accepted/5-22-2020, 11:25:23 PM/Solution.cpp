// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
         
        stack<TreeNode*> stak; 
        vector<int> res; res.reserve(1000000);
        TreeNode* lastVisited = nullptr; 
        while(!stak.empty() || root) {
            if (root) {
                stak.push(root); 
                root = root -> left; 
            } else {
                TreeNode* tmp = stak.top(); 
                if (tmp -> right && (!lastVisited || lastVisited != tmp -> right)) {
                    root = tmp -> right; 
                } else {
                    res.push_back(tmp -> val); 
                    lastVisited = stak.top(); 
                    stak.pop(); 
                }
            }
        }
        
        return res; 
    }
};