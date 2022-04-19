// https://leetcode.com/problems/dice-roll-simulation

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        
        vector<vector<int>> dp(n + 1, vector<int>(rollMax.size(), 0)); 
        // dp[r][f] : number of sequences of length r that end with dice face f
        // f : face
        // r : roll number
        int mod = 1e9 + 7; 
        for (int i = 0; i < rollMax.size(); ++i) {
            dp[1][i] = 1; 
        }
        for (int r = 2; r <= n; ++r) {
            int sum = 0; 
            for (int f = 0; f < rollMax.size(); ++f) {
                sum += dp[r - 1][f]; 
                sum = sum % mod; 
            }
            for (int f = 0; f < rollMax.size(); ++f) {
                dp[r][f] = sum; 
                if (r >= rollMax[f]) {
                    dp[r][f] = (dp[r][f] - dp[r - rollMax[f]][f] + mod) % mod; 
                }
            }
        }
        int ans = 0; 
        for (int f = 0; f < rollMax.size(); ++f) {
            ans += dp[n][f]; 
        }
        return ans; 
        
    }
};