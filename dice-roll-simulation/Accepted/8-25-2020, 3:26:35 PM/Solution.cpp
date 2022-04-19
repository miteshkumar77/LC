// https://leetcode.com/problems/dice-roll-simulation

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // dp[i][j][k] : 
        
        /*
        
            i: times in a row
            j: dice face
            k: roll number. 
            on day k, roll number j i times in a row. 
        */
        
        int mod = 1000000007; 
        vector<vector<vector<int>>> dp(16, vector<vector<int>>(7, vector<int>(n + 1, 0))); 

        
        for (int j = 1; j <= 6; ++j) {
            dp[1][j][1] = 1; 
        }
        
        for (int k = 2; k <= n; ++k) { // roll number
            for (int j = 1; j <= 6; ++j) { // dice face 
                
                // first time in a row: 
                int onceinarow = 0; 
                for (int face = 1; face <= 6; ++face) {
                    if (face != j) {
                        for (int i = 1; i <= rollMax[face - 1]; ++i) {
                            onceinarow += dp[i][face][k - 1];
                            onceinarow %= mod; 
                        }
                    }
                }
                dp[1][j][k] = onceinarow; 
                for (int i = 2; i <= rollMax[j - 1]; ++i) {
                    dp[i][j][k] = dp[i - 1][j][k - 1]; 
                }
                
            }
        }
        
        int ans = 0; 
        for (int i = 1; i <= 15; ++i) {
            for (int j = 1; j <= 6; ++j) {
                ans += dp[i][j][n]; 
                ans %= mod; 
            }
        }

        return ans; 
        
        
    }
};