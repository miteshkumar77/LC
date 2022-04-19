// https://leetcode.com/problems/coin-change

class Solution {
public:
    typedef unsigned long long int ulli;
    int coinChange(vector<int>& coins, int amount) {
        vector<ulli> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            if (dp[i] != -1) {
                for (ulli c : coins) {
                    if (c + i <= amount && (dp[c + i] == -1 || dp[c + i] > dp[i] + 1)) {
                        dp[c + i] = dp[i] + 1;
                    }
                }
            }
        }
        
        return dp.back();
    }
};