// https://leetcode.com/problems/paint-house

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int> > dp(costs.size() + 1, vector<int>(3, 0)); 
        
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                int mincost = INT_MAX; 
                for (int k = 0; k < 3; ++k) {
                    if (k != j) {
                        mincost = min(mincost, dp[i - 1][k]);
                    }
                }
                dp[i][j] = mincost + costs[i - 1][j]; 
            }
        }
        
        return min(dp.back()[0], min(dp.back()[2], dp.back()[1])); 
    }
};