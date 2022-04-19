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
    typedef unsigned int uint; 
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, array<int, 2> > depth_map; 
        dfs(root, depth_map, 0, 0); 
        int ans = 0; 
        for (auto a : depth_map) {
            ans = max(a.second[1] - a.second[0], ans);
        }  
        
        return 1 + ans; 
    }
    
    
    
    void dfs(TreeNode* root, unordered_map<int, array<int, 2> >& depth_map, int C, int D) {
        if (!root) {
            return; 
        }
        
        // cout << C << ' ' << D << endl; 
        depth_map.insert(make_pair(D, array<int, 2>{C, C}));
        depth_map[D][0] = min(depth_map[D][0], C); 
        depth_map[D][1] = max(depth_map[D][1], C); 
        dfs(root -> left, depth_map, (C << 1), D + 1); 
        dfs(root -> right, depth_map, (C << 1) + 1, D + 1); 
    }
    
    
    
    
    
};