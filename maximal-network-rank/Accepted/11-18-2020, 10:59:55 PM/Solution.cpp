// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < n; ++i) {
            graph.insert(make_pair(i, unordered_set<int>())); 
        }
        
        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        int ans = INT_MIN;
        int tmp;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                tmp = graph[i].size();
                tmp += graph[j].size();
                if (graph[i].find(j) != graph[i].end()) {
                    tmp -= 1;
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};