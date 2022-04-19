// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    
    
    int goodNodes(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int)> bt = [&](TreeNode* r, int parent) -> void {
            if (!r) return;
            if (r -> val >= parent) {
                parent = r -> val;
                ++ans;
            }
            bt(r -> left, parent);
            bt(r -> right, parent);
        };
        bt(root, INT_MIN);
        return ans;
    }
};