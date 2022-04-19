// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return vector<vector<int>>(); 
        }
        vector<vector<int>> ans; 
        deque<pair<TreeNode*, int> > dq; 
        dq.push_back(make_pair(root, 0)); 
        bool goingleft = true; 
        while(!dq.empty()) {
            pair<TreeNode*, int> top; 
            if (goingleft && dq.front().second % 2 == 1) {
                goingleft = false; 
            }
            
            if (!goingleft && dq.back().second % 2 == 0) {
                goingleft = true; 
            }
            
            if (goingleft) {
                top = dq.front(); 
                dq.pop_front(); 
                if (top.first -> left) {
                    dq.push_back(make_pair(top.first -> left, top.second + 1)); 
                }
                
                if (top.first -> right) {
                    dq.push_back(make_pair(top.first -> right, top.second + 1)); 
                }
            } else {
                top = dq.back(); 
                dq.pop_back(); 
                
                if (top.first -> right) {
                    dq.push_front(make_pair(top.first -> right, top.second + 1)); 
                }
                
                if (top.first -> left) {
                    dq.push_front(make_pair(top.first -> left, top.second + 1)); 
                }
            }
            
            if (top.second == ans.size()) {
                ans.push_back(vector<int>()); 
            }
            ans.back().push_back(top.first -> val); 
        }
        return ans; 
        
    }
};