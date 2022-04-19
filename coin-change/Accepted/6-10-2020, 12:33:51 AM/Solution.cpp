// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unsigned long long int> dp(amount + 1, -1); 
        dp[0] = 0; 
        for (unsigned long long int i = 0; i <= amount; ++i) {
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