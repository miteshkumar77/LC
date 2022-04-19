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
        unordered_map<uint, array<uint, 2> > level_map; 
        dfs(root, level_map, 0, 0, 1); 
        uint ans = 0; 
        for (auto a : level_map) {
            ans = max(ans, 1 + a.second[1] - a.second[0]); 
        }
        return ans; 
    }
    
    
    void dfs(TreeNode* root, unordered_map<uint, array<uint, 2> >& level_map, uint C, uint depth, uint power) {
        if (!root) {
            return; 
        }
        // cout << C << ' ' << depth << ' ' << power << endl; 
        level_map.insert(make_pair(depth, array<uint, 2>{INT_MAX, 0}));
        
        level_map[depth][0] = min(level_map[depth][0], C); 
        level_map[depth][1] = max(level_map[depth][1], C); 
        dfs(root -> left, level_map, C , depth + 1, power * 2); 
        dfs(root -> right, level_map, C | power, depth + 1, power * 2);
    }
    
    
};