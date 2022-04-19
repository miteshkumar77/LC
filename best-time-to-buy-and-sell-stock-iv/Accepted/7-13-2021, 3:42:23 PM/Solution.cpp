// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        /*
            dp[i][j] = highest profit we can make 
        */
        
        if (k > prices.size()/2) {
            int t = 0;
            for (int i = 1; i < prices.size(); ++i) {
                t += max(prices[i] - prices[i-1], 0);
            }
            return t;
        }
        int n = prices.size();
        vector<int> dp(n, 0);
        int maxtr, tmp;
        int ans = 0;
        for (int trade = 1; trade <= k; ++trade) {
            maxtr = INT_MIN;
            for (int price = 0; price < n; ++price) {
                tmp = dp[price] - prices[price];
                if ((price+1) < trade*2) {
                    dp[price] = (int)-1e9;
                } else {
                    dp[price] = max(prices[price] + maxtr, dp[price-1]);
                }
                ans = max(ans, dp[price]);
                maxtr = max(maxtr, tmp);
            }
        }
        return ans;
    }
};