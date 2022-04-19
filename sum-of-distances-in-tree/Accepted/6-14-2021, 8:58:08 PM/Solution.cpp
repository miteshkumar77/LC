// https://leetcode.com/problems/sum-of-distances-in-tree

class Solution {
public:
    array<int,2> dfs(int node, int parent, vector<vector<int>>& graph, vector<unordered_map<int,array<int,2>>>& dp) {
        if (parent != -1 && dp[parent].count(node)) return dp[parent][node];
        int dist = 0;
        int total = 1;
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            auto a = dfs(neighbor, node, graph, dp);
            dist += a[0] + a[1];
            total += a[1];
        }
        if (parent != -1) dp[parent][node] = {dist, total};
        return {dist, total};
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<unordered_map<int, array<int,2>>> dp(n);
        vector<vector<int>> graph(n);
        for (const auto& v : edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = dfs(i, -1, graph, dp)[0];
        }
        return ans;
    }
};