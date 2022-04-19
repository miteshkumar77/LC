// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) dp[i][0] = i;
        for (int i = 1; i <= m; ++i) dp[0][i] = i;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int add = 2 * (word1[i - 1] != word2[j - 1]);
                dp[i][j] = min(dp[i - 1][j - 1] + add, 1 + min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp.back().back();
    }
};