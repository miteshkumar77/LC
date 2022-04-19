// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsf = INT_MAX; 
        int mp = 0; 
        
        for (int i = 0; i < prices.size(); ++i) {
            mp = max(mp, prices[i] - minsf); 
            minsf = min(minsf, prices[i]); 
        }
        return mp; 
    }
};