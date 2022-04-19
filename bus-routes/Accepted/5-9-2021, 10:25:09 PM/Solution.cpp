// https://leetcode.com/problems/bus-routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, unordered_set<int>> stations;
        {
            int ridx = 0;
            for (const auto& r : routes) {
                for (int i : r) {
                    stations[i].insert(ridx);
                }
                ++ridx;
            }
        }
        
        unordered_set<int> visited;
        queue<array<int, 2>> q;
        q.push({source, 0});
        array<int, 2> t;
        while(!q.empty()) {
            t = q.front(); q.pop();
            if (t[0] == target) {
                return t[1];
            }
            if (visited.count(t[0])) continue;
            visited.insert(t[0]);
            while(!stations[t[0]].empty()) {
                int ri = *stations[t[0]].begin();
                stations[t[0]].erase(stations[t[0]].begin());
                while(!routes[ri].empty()) {
                    q.push({routes[ri].back(), t[1] + 1});
                    if (stations[routes[ri].back()].count(ri)) {
                        stations[routes[ri].back()].erase(ri);
                    }                        
                    routes[ri].pop_back();
                }
            }
        }
        return -1;
    }
};