// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return vector<int>{0};
        }
        unordered_map<int, unordered_set<int>> graph;
        for (auto e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
        unordered_set<int> ans;
        
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) {
                ans.insert(*graph[i].begin());
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
        
        
    }
};