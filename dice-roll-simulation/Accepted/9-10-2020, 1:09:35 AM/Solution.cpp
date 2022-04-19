// https://leetcode.com/problems/dice-roll-simulation

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        
        vector<vector<int>> dp(n + 1, vector<int>(7, 0)); 
        // dp[r][f] : number of sequences of length r that end with dice face f
        // f : face
        // r : roll number
        int mod = 1e9 + 7; 
        for (int i = 0; i < 6; ++i) {
            dp[1][i] = 1; 
        }
        dp[0][6] = 1; 
        dp[1][6] = 6; 
        for (int r = 2; r <= n; ++r) {
            for (int f = 0; f < 6; ++f) {
                for (int i = 1; i <= r && i <= rollMax[f]; ++i) {
                    dp[r][f] = ((dp[r][f] + dp[r - i][6]) % mod  - dp[r - i][f] + mod) % mod;                     
                }
                
                dp[r][6] =(dp[r][6] + dp[r][f]) % mod; 
            }
        }
        
        int ans = 0; 
        for (int f = 0; f < 6; ++f) {
            ans += dp[n][f]; 
            ans = ans % mod; 
        }
        return ans; 
        
    }
};