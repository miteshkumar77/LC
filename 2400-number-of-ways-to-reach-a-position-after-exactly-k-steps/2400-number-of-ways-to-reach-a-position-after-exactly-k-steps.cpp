class Solution {
public:
    int M = 1e9 + 7;
    int nCk(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                dp[i][j] %= M;
            }
        }
        return dp[n][k];
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        int m = endPos - startPos;
        for (int f = 0, b = k; f <= k; ++f, --b) {
            if ((f - b) == (endPos - startPos)) {
                return nCk(f + b, min(f, b));
            }
        }
        return 0;
        // 3 4 5 6 
        // 1 2 3 4 
        
        // f - b = endPos - startPos
        // f + b = k
        // f = endPos - startPos + k
        // 
        // 
        // f = endPos - startPos + k
        // b = startPos - endPos
    }
};