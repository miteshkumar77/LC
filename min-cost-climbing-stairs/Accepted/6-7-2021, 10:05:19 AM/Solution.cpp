// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp1 = 0;
        int dp2 = 0;
        int dp;
        for (int i = 2; i <= n; ++i) {
            dp = min(dp1 + cost[i-1], dp2 + cost[i-2]);
            // cout << "dp2: " << dp2 << " dp1: " << dp1 << " dp: " << dp <<  " cost[i-2]: " << cost[i-2] << " cost[i-1]: " << cost[i-1] << endl;
            dp2 = dp1;
            dp1 = dp;
        }
        
        return dp1;
    }
};

/* [1,100,1,1,1,100,1,1,100,1] */
/*  0 0   1 2 3  4  4 5  6  6                                              */ 