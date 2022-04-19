// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min_p = INT_MAX;
        int max_p = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_p) {
                min_p = prices[i];
            } else {
                if (prices[i] - min_p > max_p) {
                    max_p = prices[i] - min_p;
                }
            }
        }
        
        return max_p;
    }
};




// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mp = 0;
//         for (int i = 1; i < prices.size(); i++) {
//             for (int j = 0; j < i; j++) {
//                 if (prices[i] - prices[j] > mp) {
//                     mp = prices[i] - prices[j];
//                 }
//             }
//         }
        
//         return mp;
//     }
// };