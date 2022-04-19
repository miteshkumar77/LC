// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (prices[i] - prices[j] > mp) {
                    mp = prices[i] - prices[j];
                }
            }
        }
        
        return mp;
    }
};