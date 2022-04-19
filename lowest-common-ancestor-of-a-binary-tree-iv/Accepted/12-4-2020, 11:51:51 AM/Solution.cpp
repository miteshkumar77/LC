// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv

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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> need(nodes.begin(), nodes.end());
        TreeNode* result = nullptr;
        function<bool(TreeNode*)> setTree = [&](TreeNode* cur) -> bool {
            if (!cur) {
                return false;
            }  
            
            bool lr = setTree(cur -> left);
            bool rr = setTree(cur -> right);
            bool cr = need.find(cur) != need.end();
            
            if ((lr && rr) || cr) {
                result = cur; 
                return true;
            }
            return lr || rr || cr;
        };
        
        setTree(root);
        
        return result;
    }
};