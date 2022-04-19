// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_set<int>> graph;
        for (vector<int> i : roads) {
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = graph[i].size() + graph[j].size();
                if (graph[i].find(j) != graph[i].end()) {
                    --tmp;
                }
                ans = max(ans, tmp);
            }
        }
        
        return ans;
    }
};