// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        int prev_diag = 0;
        int tmp = 0;
        int ans = 0;
        for (int i = n; i >= 1; --i) {
            prev_diag = dp[0];
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s[j - 1]) {
                    tmp = prev_diag + 1;
                } else {
                    tmp = max(dp[j - 1], dp[j]);
                }
                prev_diag = dp[j];
                dp[j] = tmp;
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};