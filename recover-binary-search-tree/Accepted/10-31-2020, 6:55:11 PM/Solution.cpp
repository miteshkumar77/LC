// https://leetcode.com/problems/recover-binary-search-tree

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
    void recoverTree(TreeNode* root) {
        
        TreeNode* prev = nullptr;
        TreeNode* last = nullptr;
        TreeNode* first = nullptr;
        function<void(TreeNode*, bool)> dfs = [&](TreeNode* cur, bool replace) -> void {
            if (!cur) return;
            
            dfs(cur -> left, replace);
            if (replace) {
                if (!first && cur -> val > last -> val) {
                    first = cur;
                }
            } else {
                if (prev && cur -> val < prev -> val) {
                    last = cur;
                }
                prev = cur;
            }
            dfs(cur -> right, replace);
        };
        
        dfs(root, false);
        dfs(root, true);
        swap(last -> val, first -> val);
        
    }
};