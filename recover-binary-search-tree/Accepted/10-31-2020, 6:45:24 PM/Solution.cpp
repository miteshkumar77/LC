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
        vector<TreeNode*> inorder;
        TreeNode* prev = nullptr;
        int l = -1;
        function<void(TreeNode*)> dfs = [&](TreeNode* cur) -> void {
            if (!cur) return;
            
            dfs(cur -> left);
            if (prev) {
                if (!(cur -> val > prev -> val)) {
                    l = inorder.size();
                }
            }
            inorder.push_back(cur);
            prev = cur;
            dfs(cur -> right);
        };
        dfs(root);
        
        for (auto v : inorder) cout << v -> val << ' ';
        cout << endl;
        
        int f = l - 1;
        while(f > 0 && inorder[f - 1] -> val > inorder[l] -> val) {
            --f;
        }
        
        cout << l << endl;
        cout << f << endl;
        swap(inorder[f] -> val,
             inorder[l] -> val);
        
    }
};