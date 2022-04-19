// https://leetcode.com/problems/balance-a-binary-search-tree

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> vec;
        function<void(TreeNode*)> dfs = [&](TreeNode* tn) -> void {
            if (!tn) return;
            dfs(tn -> left);
            vec.push_back(tn);
            dfs(tn -> right);
            tn -> left = nullptr;
            tn -> right = nullptr;
        };
        
        dfs(root);
        
        function<TreeNode*(int,int)> buildTree = [&](int l, int r) -> TreeNode* {

            if (l > r) {
                
                return nullptr;
            }
            
            if (l == r) {
                return vec[l];
            }
            
            int mid = l + (r - l)/2;
            
            vec[mid] -> left = buildTree(l, mid - 1);
            vec[mid] -> right = buildTree(mid + 1, r);
            return vec[mid];
        };
        
        return buildTree(0, vec.size() - 1);
    }
};