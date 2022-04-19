// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        std::vector<TreeNode*> level;
        level.push_back(root);
        return helper(level, 0);
    }
    
    int helper(std::vector<TreeNode*> level, int i) {
        if (level.size() == 0) {
            return i;
        }
        
        std::vector<TreeNode*> n;
        for (int j = 0; j < level.size(); j++) {
            if (level[j] -> left) {
                n.push_back(level[j] -> left);
            }
            
            if (level[j] -> right) {
                n.push_back(level[j] -> right);
            }
        }
        
        return helper(n, i + 1);
    }
};