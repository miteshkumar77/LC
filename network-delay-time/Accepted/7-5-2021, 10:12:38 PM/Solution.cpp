// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dists(n+1, -1);
        vector<vector<pair<int,int>>> graph(n+1);
        for (auto const & e : times) {
            graph[e[0]].push_back({e[2], e[1]});
        }
        pq.push({0, k});
        int visited = 0;
        while(!pq.empty()) {
            const auto [dist, node] = pq.top(); pq.pop();
            if (dists[node] != -1) continue;
            ++visited;
            dists[node] = dist;
            for (auto const & neighbor : graph[node]) {
                pq.push({dist + neighbor.first, neighbor.second});
            }
        }
        if (visited != n) return -1;
        return *max_element(dists.begin()+1, dists.end());
    }
};