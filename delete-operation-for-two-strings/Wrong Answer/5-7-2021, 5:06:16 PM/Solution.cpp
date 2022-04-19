// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> dp(n + 1, 0);
        int prev_d;
        int curr;
        for (int i = 0; i < m; ++i) {
            prev_d = dp[0];
            ++dp[0];
            for (int j = 1; j <= n; ++j) {
                curr = dp[j];
                dp[j] = min((word1[j - 1] != word2[i] ? 1 : 0) + dp[j], min(1 + dp[j - 1], 2 + prev_d));  
                prev_d = curr;
            }
        }
        return dp.back();
    }
};