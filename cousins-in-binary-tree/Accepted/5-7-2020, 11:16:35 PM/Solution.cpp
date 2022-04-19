// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool isCousins(TreeNode* root, int x, int y) {
        list<TreeNode*> parent {root}; 
        return bfs(parent, x, y); 
    }
    
    bool bfs(list<TreeNode*>& parents, int x, int y) {
        
        if (parents.size() == 0) {
            return false; 
        }
        int finds = 0; 
        
        list<TreeNode*> next; 
        
        for (TreeNode* p : parents) {
            TreeNode* l = p -> left; 
            TreeNode* r = p -> right; 
            if (l && r) {
                if (((l -> val) == x || (l -> val) == y) && ((r -> val) == x || (r -> val) == y)) {
                    return false; 
                }
            }
            
            if (l && (l -> val == x || l -> val == y)) {
                ++finds; 
            } else if (r && (r -> val == x || r -> val == y)) {
                ++finds; 
            }
            
            if (finds == 2) {
                return true; 
            }
            
            if (l) {
                next.push_back(l); 
            }
            
            if (r) {
                next.push_back(r); 
            }
        }
        
        return bfs(next, x, y); 
    }
};