// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(k + 1, 0));
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                if (prices[i - 1] < prices[i]) {
                    dp[i][j] = dp[i - 1][j] + prices[i] - prices[i - 1]; 
                } else {
                    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]); 
                }
            }
        }
        int ans = 0; 
        for (int i = 1; i <= k; ++i) {
            ans = max(ans, dp.back()[i]); 
        }
        return ans; 
        
    }
};