// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; 
        unordered_map<int, vector<int>> buckets; 
        int minc = 0; 
        int maxc = 0; 
        function<void(TreeNode*,int)> bfs = [&](TreeNode* root, int x) {
            
            queue<pair<TreeNode*, int>> q; 
            q.push(make_pair(root, 0)); 
            while(!q.empty()) {
                TreeNode* r = q.front().first;
                int c = q.front().second; 
                q.pop(); 
                buckets[c].push_back(r -> val); 
                minc = min(c, minc); 
                maxc = max(c, maxc); 
                if (r -> left) {
                    q.push(make_pair(r -> left, c - 1)); 
                }
                if (r -> right) {
                    q.push(make_pair(r -> right, c + 1)); 
                }
            }
        };
        bfs(root, 0); 
        for (int i = minc; i <= maxc; ++i) {
            ans.push_back(buckets[i]); 
        }
        return ans; 
        
    }
};