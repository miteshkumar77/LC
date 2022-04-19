class Solution {
public:
    int minimumWhiteTiles(string floor, int C, int L) {
        int n = floor.length();
        vector<vector<int>> dp(C+1, vector<int>(n+1, 0));
        for (int f = 1; f <= n; ++f)
            dp[0][f] = dp[0][f-1] + (floor[f-1] == '1');
        
        for (int c = 1; c <= C; ++c) {
            
            for (int f = 0; f <= n; ++f) {
                if (f < L) {
                    dp[c][f] = 1e9 + 7;
                } else {
                    dp[c][f] = min(dp[c][f-1] + (floor[f-1] - '0'), 
                                  (f >= c * L) ? dp[c-1][f-L] : dp[c-1][f - f % L]);
                }
            }
        }
        return dp[C][n];
    }
};