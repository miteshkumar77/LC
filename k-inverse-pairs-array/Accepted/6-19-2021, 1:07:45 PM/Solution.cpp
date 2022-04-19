// https://leetcode.com/problems/k-inverse-pairs-array

class Solution {
public:
    
    int kInversePairs(int n, int k) {
        /*
            dp[i][j]: ways to arrange sticks 1 through i with exactly j inversions
            if (i < j) dp[i][j] = 0;
            else dp[i][j] = sum(dp[i-1][x], x = 0 through j);
        */
        int M = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
        }
        int pref;
        for (int i = 2; i <= n; ++i) {
            pref = 1;
            for (int j = 1; j <= k; ++j) {
                pref = (pref + dp[i-1][j]) % M;
                if (j >= i) pref = (pref + M - dp[i-1][j-i]) % M;
                dp[i][j] = pref;
            }
        }   
        return dp[n][k];
    }
};