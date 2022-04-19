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
        unordered_map<int, vector<pair<int, int>>> buckets; 
        int minc = 0; 
        int maxc = 0; 
        function<void(TreeNode*,int)> bfs = [&](TreeNode* root, int x) {
            
            queue<tuple<TreeNode*,int,int>> q; 
            q.push(make_tuple(root, 0, 0));
            
            while(!q.empty()) {
                TreeNode* r = get<0>(q.front()); 
                int c = get<1>(q.front()); 
                int clk = get<2>(q.front()); 
                minc = min(minc, c); 
                maxc = max(maxc, c); 
                q.pop(); 
                if (buckets[c].size() != 0 && buckets[c].back().second == clk) {
                    int tmp = buckets[c].back().first; 
                    buckets[c].back().first = min(tmp, r -> val); 
                    buckets[c].push_back(make_pair(max(tmp, r -> val), clk)); 
                } else {
                    buckets[c].push_back(make_pair(r -> val, clk)); 
                }
                
                if (r -> left) {
                    q.push(make_tuple(r -> left, c - 1, clk + 1)); 
                }
                if (r -> right) {
                    q.push(make_tuple(r -> right, c + 1, clk + 1)); 
                }
            }
            
        };
        bfs(root, 0); 
        for (int i = minc; i <= maxc; ++i) {
            vector<int> lvl; 
            for (auto p : buckets[i]) {
                lvl.push_back(p.first); 
            }
            ans.push_back(lvl); 
        }
        return ans; 
        
    }
};