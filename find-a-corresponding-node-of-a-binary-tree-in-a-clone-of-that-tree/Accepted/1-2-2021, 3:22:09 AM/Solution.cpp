// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    typedef TreeNode TN;
    TN* getTargetCopy(TN* o, TN* c, TN* t) {
        if (!c || o == t) return c;
        TN* res = getTargetCopy(o->left, c->left, t);
        return res?res:getTargetCopy(o->right, c->right, t);
    }
};