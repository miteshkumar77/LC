// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        
        
        
        
        if (prices.size() <= 1) {
            return 0; 
        }
        
        int ans = 0; 

        if (k >= prices.size()/2) {
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1]; 
            }
            return ans; 
        }
        vector<int> dp(prices.size(), 0); 
        
        for (int i = 1; i <= k; ++i) {
            vector<int> dpn(prices.size(), 0); 
            for (int j = 1; j < prices.size(); ++j) {
                int buy = dpn[j - 1]; 
                int sell = INT_MIN; 
                for (int x = 0; x <= j; ++x) {
                    sell = max(sell, dp[x] - prices[x]); 
                }
                sell += prices[j];
                dpn[j] = max(buy, sell); 
            }
            ans = max(ans, dpn.back()); 
            dp.swap(dpn); 
        }
        
        
        
        
        return ans; 
    }
};