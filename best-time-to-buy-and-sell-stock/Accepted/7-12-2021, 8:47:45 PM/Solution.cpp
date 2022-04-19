// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0];
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans = max(ans, prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        return ans;
    }
};