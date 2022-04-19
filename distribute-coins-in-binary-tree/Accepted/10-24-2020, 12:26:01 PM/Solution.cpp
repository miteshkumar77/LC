// https://leetcode.com/problems/distribute-coins-in-binary-tree

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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> solver = [&](TreeNode* r) -> int {
            if (!r) return 0;
            r -> val -= solver(r -> left) + solver(r -> right);
            ans += abs(r -> val - 1);
            return 1 - r -> val;
        };
        solver(root);
        return ans;
    }
};