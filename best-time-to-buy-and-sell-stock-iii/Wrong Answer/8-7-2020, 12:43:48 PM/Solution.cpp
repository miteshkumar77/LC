// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> leftMax(prices.size()); 
        vector<int> rightMax(prices.size()); 
        int n = prices.size() - 1; 
        leftMax[0] = 0; 
        rightMax[n] = 0; 
        
        int lmin = prices[0]; 
        int rmax = prices[n]; 
        for (int i = 1; i <= n; ++i) {
            int j = n - i; 
            leftMax[i] = max(leftMax[i - 1], prices[i] - lmin); 
            lmin = min(lmin, prices[i]); 
            
            rightMax[j] = max(rightMax[j + 1], rmax - prices[i]); 
            rmax = max(rmax, prices[j]); 
        }
        int ans = 0; 
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, leftMax[i - 1] + rightMax[i]);
        }
        return ans; 
        
    }
};