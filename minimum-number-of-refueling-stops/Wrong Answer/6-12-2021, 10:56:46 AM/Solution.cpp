// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int tank = startFuel;
        int stops = 0;
        int dist = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= n; ++i) {
            tank -= (i == n ? target : stations[i][0]) - dist;
            dist = (i == n ? target : stations[i][0]);
            while(tank < 0 && !pq.empty()) {
                tank += pq.top(); pq.pop(); ++stops;
            }
            if (tank < 0) return -1;
            if (i < n) pq.push(stations[i][1]);
        }
        return stops;
    }
};