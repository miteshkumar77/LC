class Solution {
public:
    
    void top_sort(unordered_map<int, vector<int>>& graph, vector<int>& ts, int node, unordered_set<int>& pre, unordered_set<int>& post, bool& cycle) {
        if (pre.count(node)) {
            if (!post.count(node)) {
                cycle = true;
            }
        } else {
            pre.insert(node);
            for (auto & n : graph[node]) {
                top_sort(graph, ts, n, pre, post, cycle);
                if (cycle) return;
            }
            post.insert(node);
            ts.push_back(node);
        }
    }
    vector<int> indices(vector<vector<int>>& cons, int k) {
        unordered_map<int, vector<int>> graph;
        for (int i = 1; i <= k; ++i) {
            graph.insert({i, {}});
        }
        for (auto e : cons) {
            graph[e[0]].push_back(e[1]);
        }
        bool cycle{false};
        unordered_set<int> pre;
        unordered_set<int> post;
        vector<int> ts; ts.reserve(k);
        for (int i = 1; i <= k; ++i) {
            if (!pre.count(i)) {
                top_sort(graph, ts, i, pre, post, cycle);
                if (cycle) return {};
            }
        }
        reverse(ts.begin(), ts.end());
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[ts[i]-1] = i;
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto rows = indices(rowConditions, k);
        auto cols = indices(colConditions, k);
        if (rows.empty() || cols.empty()) return {};
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 0; i < k; ++i) {
            ans[rows[i]][cols[i]] = i+1;
        }
        return ans;
    }
};