// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> tree(n, vector<int>()); 
        for (vector<int> e : edges) {
            tree[e[0]].push_back(e[1]); 
            tree[e[1]].push_back(e[0]); 
        }
        vector<int> ans(n, 0); 
        dfs(0, labels, tree, ans, -1);
        return ans; 
    }
    
    
    array<int, 26> dfs(int node, string& label, vector<vector<int> >& tree, vector<int>& ans, int parent) {
        array<int, 26> my{0};
        ++my[label[node] - 'a'];
        for (int n : tree[node]) {
            if (n != parent) {
                array<int, 26> tmp = dfs(n, label, tree, ans, node);
                for (int i = 0; i < 26; ++i) {
                    my[i] += tmp[i]; 
                }
            }
        }
        
        ans[node] = my[label[node] - 'a'];
        return my; 
        
    }
};