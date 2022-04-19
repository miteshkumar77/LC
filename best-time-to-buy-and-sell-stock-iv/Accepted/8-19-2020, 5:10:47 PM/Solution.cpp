// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0; 
        }
        vector<int> dp(prices.size(), 0); 
        k = min((int)k, (int)prices.size()/2); 
        int ans = 0; 
        for (int i = 1; i <= k; ++i) {
            vector<int> dpn(prices.size(), 0); 
            int max_buy = dp[0] - prices[0]; 
            for (int j = 1; j < prices.size(); ++j) {
                int buy = dpn[j - 1]; 
                int sell = prices[j] + max_buy; 
                max_buy = max(max_buy, dp[j] - prices[j]);
                dpn[j] = max(buy, sell); 
            }
            ans = max(ans, dpn.back()); 
            dp.swap(dpn); 
        }
        return ans; 
    }
};