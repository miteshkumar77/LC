// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<array<int, 3> > dp(prices.size() + 1, array<int, 3>{0, 0, 0}); 
        // 0: sell
        // 1: buy
        // 2: cooldown
        int n = prices.size(); 
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + prices[i - 1] - prices[i - 2];
            dp[i][1] = dp[i - 1][2];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]);
        }
        
        return max(max(dp[n][0], dp[n][1]), dp[n][2]); 
    }
};