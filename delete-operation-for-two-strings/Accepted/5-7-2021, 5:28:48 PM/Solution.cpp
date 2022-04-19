// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        if (word1.length() < word2.length()) {
            return minDistance(word2, word1);
        }
        int n = word1.length();
        int m = word2.length();
        vector<int> dp(m, 0);
        for (int i = 1; i <= m; ++i) dp[i-1] = i;
        int curr;
        int prevd;
        int prev;
        int add;
        for (int i = 0; i < n; ++i) {
            prevd = i;
            prev = i + 1;
            for (int j = 0; j < m; ++j) {
                curr = dp[j];
                add = (word1[i] != word2[j]) * 2;
                dp[j] = min(prevd + add, 1 +min(dp[j], prev));
                prevd = curr;
                prev = dp[j];
            }
        }
        return dp.back();
    }
};