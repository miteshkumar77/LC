// https://leetcode.com/problems/optimize-water-distribution-in-a-village

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            edges.push_back({wells[i], i, n});
        }
        for (int i = 0; i < pipes.size(); ++i) {
            pipes[i][0]--;
            pipes[i][1]--;
            edges.push_back({pipes[i][2], pipes[i][1], pipes[i][0]});
        }
        vector<int> parent(n + 1, -1);
        
        function<int(int)> find = [&](int node) -> int {
            if (parent[node] == -1) return node;
            parent[node] = find(parent[node]);
            return parent[node];
        };
        
        function<bool(int,int)> onion = [&](int a, int b) -> int {
            int pa = find(a); int pb = find(b);
            if (pa == pb) return true;
            parent[pa] = pb;
            return false;
        };
        sort(edges.begin(), edges.end(), [](vector<int> const & a, vector<int> const& b) {
            return a[0] < b[0];
        });
        
        
        int ans = 0;
        for (auto const& e : edges) {
            if (!onion(e[1], e[2])) {
                ans += e[0];
            }
        }
        return ans;
    }
};