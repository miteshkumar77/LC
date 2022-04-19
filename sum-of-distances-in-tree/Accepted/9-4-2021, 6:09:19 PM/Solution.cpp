// https://leetcode.com/problems/sum-of-distances-in-tree

class Solution {
public:
    
    array<int, 2> calc(int parent, int node, vector<unordered_map<int, array<int, 2>>>& dp, vector<vector<int>>& graph) {
        if (parent == -1 || dp[parent][node] == array<int, 2>{-1, -1}) {
            array<int, 2> ans = {1, 0};
            for (auto neighbor : graph[node]) {
                if (neighbor != parent) {
                    auto r = calc(node, neighbor, dp, graph);
                    ans[0] += r[0];
                    ans[1] += r[1] + r[0];
                }
            }
            if (parent != -1) {
                dp[parent][node] = ans;
            }
            return ans;
        }
        return dp[parent][node];
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        vector<unordered_map<int,array<int, 2>>> dp(n);
        for (auto const& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
            dp[e[0]][e[1]] = {-1, -1};
            dp[e[1]][e[0]] = {-1, -1};
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = calc(-1, i, dp, tree)[1];
        }
        return ans;
    }
};