// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // dp[i][0]: buy on day i
        // dp[i][1]: sell on day i
        // dp[i][2]: cooldown on day i
        
        vector<array<int, 3>> dp(n, {prices[0] * -1, (int)-1e9, (int)-1e9});
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0] + prices[i - 1] - prices[i], dp[i - 1][2] - prices[i]);
            dp[i][1] = max(dp[i - 1][1] - prices[i - 1] + prices[i], dp[i - 1][0] + prices[i]);
            dp[i][2] = dp[i - 1][1];
        }
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};