// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    typedef signed long long int slli;
    int minRefuelStops(slli target, slli startFuel, vector<vector<int>>& stations) {
        slli prev_position = 0;
        slli distance;
        slli fuel;
        slli val;
        slli n = stations.size(); 
        vector<vector<slli>> dp(n + 1, vector<slli>(n + 1, -1)); 
        dp[0][0] = startFuel;
        for (slli station = 1; station <= n; ++station) {
            distance = stations[station - 1][0] - prev_position;
            fuel = stations[station - 1][1];
            val = -1;
            for (slli stops = 0; stops <= station; ++stops) {
                if (dp[station - 1][stops] != -1 && dp[station - 1][stops] >= distance) {
                    dp[station][stops] = dp[station - 1][stops] - distance;
                }
                if (stops != 0 && dp[station - 1][stops - 1] != -1 && dp[station - 1][stops - 1] >= distance) {
                    dp[station][stops] = max(dp[station][stops], dp[station - 1][stops - 1] - distance + fuel); 
                }
            }
            prev_position = stations[station - 1][0]; 
        }
        for (slli stops = 0; stops <= n; ++stops) {
            if (dp[n][stops] != -1 && dp[n][stops] + prev_position >= target) {
                return stops;
            }
        }
        return -1;
    }
};