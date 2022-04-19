// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1); 
        dp[0] = 0; 
        for (int i = 0; i <= amount; ++i) {
            if (dp[i] != -1) {
                for (int c : coins) {
                    if (i + c <= amount && (dp[i + c] == -1 || dp[i + c] > dp[i] + 1)) {
                        dp[i + c] = dp[i] + 1; 
                    } 
                }
            }
        }
        return dp.back(); 
    }
};