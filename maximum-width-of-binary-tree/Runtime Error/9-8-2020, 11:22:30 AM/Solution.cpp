// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    typedef TreeNode T; 
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0; 
        }
        vector<T*> lvl{root}; 
        vector<int> idx{0};
        int ans = 0; 
        while(lvl.size() != 0) {
            vector<T*> next; 
            vector<int> nextidx; 
            ans = max(ans, idx.back() + 1 - idx[0]); 
            for (int i = 0; i < lvl.size(); ++i) {
                if (lvl[i] -> left) {
                    next.push_back(lvl[i] -> left); 
                    nextidx.push_back(idx[i] * 2); 
                }
                if (lvl[i] -> right) {
                    next.push_back(lvl[i] -> right); 
                    nextidx.push_back(idx[i] * 2 + 1); 
                }
            }
            lvl.swap(next); 
            idx.swap(nextidx); 
        }
        return ans; 
        
    }
};