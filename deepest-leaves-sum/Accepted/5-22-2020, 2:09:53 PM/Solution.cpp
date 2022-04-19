// https://leetcode.com/problems/deepest-leaves-sum

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
    int deepestLeavesSum(TreeNode* root) {
        list<TreeNode*> prev; 
        if (root) {
            prev.push_back(root); 
        }
        while(prev.size() != 0) {
            list<TreeNode*> next; 
            for (auto iter = prev.begin(); iter != prev.end(); ++iter) {
                if ((*iter) -> left) {
                    next.push_back((*iter) -> left); 
                }
                if ((*iter) -> right) {
                    next.push_back((*iter) -> right); 
                }
                
            }
            
            if (next.size() == 0) {
                int sum = 0; 
                for (TreeNode* node : prev) {
                    sum += node -> val; 
                }
                return sum; 
            }  
            prev.swap(next); 
        }
        return 0; 
    }
};