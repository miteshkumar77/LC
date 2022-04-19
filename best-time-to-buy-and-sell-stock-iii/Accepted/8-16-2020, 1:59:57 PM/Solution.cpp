// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0; 
        }
        int n = prices.size() - 1; 
        vector<int> rightMax(n + 1); 
        int rMin = prices[n]; 
        int rMax = prices[n];
        rightMax[n] = 0; 
        
        for (int i = n - 1; i >= 0; --i) {
            if (prices[i] < rMin) {
                rMin = prices[i]; 
            }
            
            if (prices[i] > rMax) {
                rMax = prices[i]; 
                rMin = prices[i]; 
            }
            
            rightMax[i] = max(rMax - rMin, rightMax[i + 1]); 
        }
        rightMax.push_back(0); 
        
//         for (auto i : rightMax) cout << i << ' ';
//         cout << endl; 
        int ans = rightMax[1]; 
        
        int maxLeftProfit = 0; 
        int minLeft = prices[0]; 
        int maxLeft = prices[0]; 
        // cout << 0 << ' '; 
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minLeft) {
                maxLeft = prices[i]; 
                minLeft = prices[i]; 
            }
            
            if (prices[i] > maxLeft) {
                maxLeft = prices[i]; 
            }
            
            maxLeftProfit = max(maxLeftProfit, maxLeft - minLeft); 
            // cout << maxLeftProfit << ' '; 
            ans = max(maxLeftProfit + rightMax[i + 1], ans); 
        }
        // cout << endl;
        return ans; 
    }
};