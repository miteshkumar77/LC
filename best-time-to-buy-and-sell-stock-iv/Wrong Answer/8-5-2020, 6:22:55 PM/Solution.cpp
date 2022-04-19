// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        priority_queue<int, vector<int>, greater<int>> minq; 
        int run = 0;  
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] >= prices[i - 1]) {
                run += prices[i] - prices[i - 1]; 
            } else {
                minq.push(run); 
                run = 0; 
            }
            
            if (minq.size() > k) {
                minq.pop(); 
            }
        }
        minq.push(run); 
        if (minq.size() > k) {
            minq.pop(); 
        }
        
        
        int ans = 0; 
        while(!minq.size() == 0) {
            ans += minq.top(); minq.pop(); 
        }
        return ans; 
        
    }
};