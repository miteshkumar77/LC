// https://leetcode.com/problems/find-nearest-right-node-in-binary-tree

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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<pair<TreeNode*, int>> bfsq;
        int prevLvl = -1;
        TreeNode* prevNode = nullptr;
        bfsq.push(make_pair(root, 0));
        while(!bfsq.empty()) {
            const auto&[node, lvl] = bfsq.front();
            bfsq.pop();
            if (!node) continue;
            bfsq.push(make_pair(node->left, lvl+1));
            bfsq.push(make_pair(node->right,lvl+1)); 
            if (prevNode == u) {
                if (lvl != prevLvl) return nullptr;
                return node;
            }
            prevLvl = lvl;
            prevNode = node;
        }
        return nullptr;
    }
};