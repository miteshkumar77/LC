// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp1 = 0;
        int dp2 = 0;
        int dp;
        for (int i = 2; i < n; ++i) {
            dp = min(dp1 + cost[i-1], dp2 + cost[i-1]);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};