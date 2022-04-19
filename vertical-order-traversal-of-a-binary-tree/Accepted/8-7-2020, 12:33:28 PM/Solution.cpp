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
    typedef tuple<TreeNode*, int, int> tup; 
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        unordered_map<int, vector<pair<int, vector<int>>>> tables; 

        int minc = 0; 
        int maxc = 0; 
        queue<tup> q; 
        q.push(tup(root, 0, 0)); 
        while(!q.empty()) {
            TreeNode* r = get<0>(q.front()); 
            int c = get<1>(q.front()); 
            int clk = get<2>(q.front()); 
            minc = min(minc, c); maxc = max(maxc, c); 
            q.pop(); 
            
            if (tables[c].size() == 0 || clk > tables[c].back().first) {
                tables[c].push_back(make_pair(clk, vector<int>())); 
            }
            tables[c].back().second.push_back(r -> val); 
            if (r -> left) {
                q.push(tup(r -> left, c - 1, clk + 1)); 
            }
            if (r -> right) {
                q.push(tup(r -> right, c + 1, clk + 1)); 
            }
        }
        
        vector<vector<int>> ans; 
        for (int i = minc; i <= maxc; ++i) {
            ans.push_back(vector<int>()); 
            for (auto &[clk, v] : tables[i]) {
                sort(v.begin(), v.end()); 
                for (int num : v) {
                    ans.back().push_back(num); 
                }
            }
        }
        
        return ans; 
        
    }
};