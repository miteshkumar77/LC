// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(); 
        unordered_set<int> seen; 
        list<TreeNode*> nodes; 
        for (int i = 0; i < n; ++i) {
            seen.insert(inorder[i]); 

            if (seen.find(postorder[i]) == seen.end()) {
                nodes.push_back(new TreeNode(postorder[i])); 
            } else {
                TreeNode* tmp = new TreeNode(postorder[i]);
                tmp -> right = (!(nodes.size() == 0))?nodes.back():nullptr;
                if (nodes.size() != 0) {
                    nodes.pop_back(); 
                }
                tmp -> left = (!(nodes.size() == 0))?nodes.back():nullptr;
                if (nodes.size() != 0) {
                    nodes.pop_back(); 
                }                
                nodes.push_back(tmp);
            }

        }
        return nodes.back(); 
    }
};