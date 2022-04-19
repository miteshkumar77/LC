// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths

class Solution {
public:
    
    using ll = long long;
    
    void label_dist(vector<unordered_map<int,ll>>& graph, vector<ll>& d, int src) {
        priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll, 2>>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            auto [dist, node] = pq.top(); pq.pop();
            if (d[node] <= dist)
                continue;
            d[node] = dist;
            for (auto [neighbor, weight] : graph[node])
                pq.push({weight + dist, neighbor});
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<unordered_map<int,ll>> graph(n);
        vector<unordered_map<int,ll>> rgraph(n);
        for (auto& e : edges) {
            graph[e[0]][e[1]] = e[2];
            rgraph[e[1]][e[0]] = e[2];
        }
        for (auto& e : edges) {
            graph[e[0]][e[1]] = min(graph[e[0]][e[1]], (ll)e[2]);
            rgraph[e[1]][e[0]] = min(graph[e[0]][e[1]], (ll)e[2]);
        }
        vector<ll> ds1(n, LLONG_MAX);
        vector<ll> ds2(n, LLONG_MAX);
        vector<ll> dd (n, LLONG_MAX);
        
        label_dist(graph, ds1, src1);
        label_dist(graph, ds2, src2);
        label_dist(rgraph, dd, dest);
        long long ans{LLONG_MAX};
        for (int i = 0; i < n; ++i) {
            if (ds1[i] != LLONG_MAX && ds2[i] != LLONG_MAX && dd[i] != LLONG_MAX)
                ans = min(ans, ds1[i] + ds2[i] + dd[i]);
        }
        return ans == LLONG_MAX ? -1 : ans;
        
    }
};