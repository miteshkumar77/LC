// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        if (prices.size()/2 <= k) {
            int ans = 0;
            for (int i = 1; i < prices.size(); ++i) {
                ans += max(0, prices[i] - prices[i - 1]);
            }
            return ans;
        }
        
        vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
        for (int t = 1; t <= k; ++t) {
            int max_profit = dp[t - 1][0] - prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                dp[t][i] = max(dp[t][i - 1], max_profit + prices[i]);
                max_profit = max(max_profit, dp[t - 1][i] - prices[i]);
            }
        }
        return dp[k].back();
    }
};