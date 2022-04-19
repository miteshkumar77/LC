// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_buy = 0; 
        bool bought = false; 
        int ans = 0; 
        
        for (int i = 0; i < prices.size(); ++i) {
            if (!bought) {
                curr_buy = prices[i]; 
                bought = true; 
            } else {
                if (prices[i] > curr_buy) {
                     
                    ans += prices[i] - curr_buy; 
                    curr_buy = prices[i];
                } else {
                    curr_buy = prices[i]; 
                }
            }
        }
        return ans; 
    }
};