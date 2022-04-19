// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        
        while(curr) {
            if (!(curr -> left)) {
                ans.push_back(curr -> val);
                curr = curr -> right;
            } else {
                prev = curr -> left;
                while(prev -> right && prev -> right != curr) {
                    prev = prev -> right;
                }
                
                if (prev -> right == curr) {
                    prev -> right = nullptr;
                    curr = curr -> right;
                } else {
                    prev -> right = curr;
                    ans.push_back(curr -> val);
                    curr = curr -> left;
                }
            }
        }
        
        return ans;
    }
};