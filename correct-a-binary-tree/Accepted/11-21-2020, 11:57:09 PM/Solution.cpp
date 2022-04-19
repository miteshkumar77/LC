// https://leetcode.com/problems/correct-a-binary-tree

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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*, TreeNode*>> bfsq;
        bfsq.push(make_pair(nullptr, root));
        while(!bfsq.empty()) {
            auto p = bfsq.front();
            TreeNode* parent = p.first;
            TreeNode* top = p.second;
            visited.insert(top);
            bfsq.pop(); 
            if (top -> right) {
                if (visited.find(top -> right) != visited.end()) {
                    if (parent -> right == top) {
                        parent -> right = nullptr;
                    } else {
                        parent -> left = nullptr;
                    }
                    return root;
                }
                bfsq.push(make_pair(top, top -> right)); 
            }
            if (top -> left) {
                bfsq.push(make_pair(top, top -> left));
            }
        }
        return nullptr;
    }
};