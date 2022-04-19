// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    int numTilings(int N) {
        vector<array<unsigned long long int, 2> > dp(N + 1, array<unsigned long long int, 2>{0}); 
        
        
        // dp[X][0]: how many ways to tile a 2 by X board fully 
        // dp[X][1]: how many ways to tile a 2 by X board with one
        // corner left untiled. 
        
        unsigned long long int MOD = 1000000007; 
        
        dp[1][0] = 1; 
        dp[0][0] = 1; 
        for (int i = 2; i <= N; ++i) {
            dp[i][0] = (dp[i - 1][0] % MOD + dp[i - 2][0] % MOD + dp[i - 1][1] % MOD) % MOD; 
            dp[i][1] = (2 * dp[i - 2][0] % MOD + dp[i - 1][1] % MOD) % MOD;
        }
        
        return (int)(dp.back()[0] % MOD);
        
    }
};