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
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, array<signed long long int, 2> > depth_width; 
        dfs(root, 0, depth_width, 0); 
        signed long long int ans = 0; 
        for (pair<int, array<signed long long int, 2>> a : depth_width) {
            ans = max(ans, a.second[1] - a.second[0]); 
        }
        return ans; 
    }
    
    void dfs(TreeNode* root, int depth, unordered_map<int, array<signed long long int, 2> >& depth_width, signed long long int C) {
        if (!root) {
            return; 
        }
        
        depth_width.insert(make_pair(depth, array<signed long long int, 2>{0, 0})); 
        depth_width[depth][0] = min(C, depth_width[depth][0]);
        depth_width[depth][1] = max(C, depth_width[depth][1]); 
        dfs(root -> left, depth + 1, depth_width, C - 1); 
        dfs(root -> right, depth + 1, depth_width, C + 1); 
        
    }
};