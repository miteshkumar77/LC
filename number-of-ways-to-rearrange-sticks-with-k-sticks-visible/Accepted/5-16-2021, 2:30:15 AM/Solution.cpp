// https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible

class Solution {
public:
    typedef unsigned long long int ulli;
    vector<vector<ulli>> dp;
    ulli M = 1e9 + 7;
    ulli dfs(ulli n, ulli k) {
        if (n == 0 && k == 0) {
            return 1;
        } else if (n == 0 || k == 0) {
            return 0;
        } else {
            if (dp[n][k] == -1) {
                dp[n][k] = (dfs(n - 1, k - 1) + ((n-1) * dfs(n - 1, k) % M)) % M;
            }
            return dp[n][k];
        }
    }
    int rearrangeSticks(int n, int k) {
        dp = vector<vector<ulli>>(n + 1, vector<ulli>(k + 1, -1));
        /*
            dp[i][j] = number of arrangements of sticks n - i + 1 ... n with 
            j visible sticks
            dp[0][0] = 1;
        */
        return dfs(n, k);
    }
};