// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, unordered_set<int>> graph;
        
        for (auto e : edges) {
            graph[e[0]].insert(e[1]);
        }
        
        vector<int> dp(n, 0);
        
        int finishable = 0;
        
        function<bool(int)> dfs = [&](int node) -> bool {
            if (dp[node] != 0) {
                return dp[node] == 1;
            }
            
            bool canFinish = true;
            dp[node] = -1;
            for (int neighbor : graph[node]) {
                if (!dfs(neighbor)) {
                    canFinish = false;
                }
            }
            if (canFinish) {
                dp[node] = 1;
            } else {
                dp[node] = -1;
            }
            return canFinish;
        };
        
        for (int i = 0; i < n; ++i) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
        
        
    }
};