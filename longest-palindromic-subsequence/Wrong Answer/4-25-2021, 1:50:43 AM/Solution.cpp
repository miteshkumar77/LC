// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        int prev_diag = 0;
        int tmp = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            prev_diag = dp[0];
            for (int j = 1; j <= n; ++j) {
                
                if (s[n - i] == s[j - 1]) {
                    tmp = prev_diag + 1;
                } else {
                    tmp = max(dp[i - 1], dp[i]);
                }
                prev_diag = dp[i];
                dp[i] = tmp;
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};