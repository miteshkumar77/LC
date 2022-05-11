class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5, 1));
        for (int i = 2; i <= n; ++i) {
            int sum{0};
            for (int j = 0; j < 5; ++j) {
                sum += dp[i-1][j];
                dp[i][j] = sum;
            }
        }
        return accumulate(dp[n].begin(), dp[n].end(), 0);
    }
};