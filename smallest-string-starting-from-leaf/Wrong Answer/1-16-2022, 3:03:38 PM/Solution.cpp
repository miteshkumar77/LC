// https://leetcode.com/problems/smallest-string-starting-from-leaf

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
    void mod(unordered_set<TreeNode*>& v, TreeNode* root, TreeNode* par) {
        if (!root) return;
        
        if (!(root->left || root->right)) {
            v.insert(root);
        }
        mod(v, root->left, root);
        mod(v, root->right, root);
        root->left = nullptr;
        root->right = par;
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        unordered_set<TreeNode*> v;
        mod(v, root, nullptr);
        while(!v.empty()) {
            int cmin = 255;
            for (TreeNode* t : v) {
                cmin = min(cmin, t->val);
            }
            unordered_set<TreeNode*> l;
            for (TreeNode* t : v) {
                if (t->right && t->val == cmin) {
                    l.insert(t->right);
                }
            }
            l.swap(v);
            cmin+='a';
            ans.push_back((char)cmin);
        }
        return ans;
    }
};