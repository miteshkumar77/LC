// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0; 
        }
        vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0)); 
        
        
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j < prices.size(); ++j) {
                int buy = dp[i][j - 1]; 
                int sell = INT_MIN; 
                for (int x = 0; x <= j; ++x) {
                    sell = max(sell, dp[i - 1][x] - prices[x]); 
                }
                sell += prices[j];
                dp[i][j] = max(buy, sell); 
            }
        }
        int ans = 0; 
        
        
        // for (vector<int> v : dp) {
        //     for (int i : v) cout << i << ' ';
        //     cout << endl; 
        // }
        for (int i = 1; i <= k; ++i) {
            ans = max(dp[i].back(), ans);
        }
        
        return ans; 
    }
};