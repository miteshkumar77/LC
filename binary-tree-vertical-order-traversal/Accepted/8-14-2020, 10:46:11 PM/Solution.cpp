// https://leetcode.com/problems/binary-tree-vertical-order-traversal

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return vector<vector<int>>(); 
        }
        unordered_map<int, vector<int>> ans; 
        int minidx = 0; 
        int maxidx = 0; 
//         function<void(TreeNode*,int)> vorder = [&] (TreeNode* root, int i) -> void {
//             if (!root) {
//                 return; 
//             }
//             minidx = min(i, minidx); 
//             maxidx = max(i, maxidx); 
//             ans[i].push_back(root -> val); 
//             vorder(root -> left, i - 1); 
//             vorder(root -> right, i + 1); 
//         };
        
//         vorder(root, 0); 
        
        
        queue<pair<TreeNode*, int> > q; 
        q.push(make_pair(root, 0)); 
        
        while(!q.empty()) {
            TreeNode* rtop = q.front().first;
            int ltop = q.front().second; 
            q.pop(); 
            minidx = min(ltop, minidx);
            maxidx = max(ltop, maxidx); 
            ans[ltop].push_back(rtop -> val); 
            if (rtop -> left) {
                q.push(make_pair(rtop -> left, ltop - 1));
            }
            if (rtop -> right) {
                q.push(make_pair(rtop -> right, ltop + 1)); 
            }
            
        }
        vector<vector<int>> ansv; 
        for (int i = minidx; i <= maxidx; ++i) {
            ansv.push_back(ans[i]); 
        }
        return ansv; 
    }
};