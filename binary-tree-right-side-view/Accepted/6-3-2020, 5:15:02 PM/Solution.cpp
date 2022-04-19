// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; 
        list<TreeNode*> top; 
        list<TreeNode*> next;
        if (root) {
            top.push_back(root); 
            ans.push_back(root -> val); 
        }
        
        while(top.size() != 0) {
            for (TreeNode* elem : top) {
                if (elem -> left) {
                    next.push_back(elem -> left); 
                }
                if (elem -> right) {
                    next.push_back(elem -> right); 
                }
            }
            if (next.size() != 0) {
                ans.push_back(next.back() -> val); 
            }
            top.clear(); 
            top.swap(next); 
        }
        return ans; 
        
    }
};