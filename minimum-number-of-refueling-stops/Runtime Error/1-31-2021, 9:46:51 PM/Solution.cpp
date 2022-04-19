// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int prev_position = 0;
        int distance;
        int fuel;
        int val;
        int n = stations.size(); 
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); 
        dp[0][0] = startFuel;
        for (int station = 1; station <= n; ++station) {
            distance = stations[station - 1][0] - prev_position;
            fuel = stations[station - 1][1];
            val = -1;
            for (int stops = 0; stops <= station; ++stops) {
                if (dp[station - 1][stops] != -1 && dp[station - 1][stops] >= distance) {
                    dp[station][stops] = dp[station - 1][stops] - distance;
                }
                if (stops != 0 && dp[station - 1][stops - 1] != -1 && dp[station - 1][stops - 1] >= distance) {
                    dp[station][stops] = max(dp[station][stops], dp[station - 1][stops - 1] - distance + fuel); 
                }
            }
            prev_position = stations[station - 1][0]; 
        }
        for (int stops = 0; stops <= n; ++stops) {
            if (dp[n][stops] != -1 && dp[n][stops] + prev_position >= target) {
                return stops;
            }
        }
        return -1;
    }
};