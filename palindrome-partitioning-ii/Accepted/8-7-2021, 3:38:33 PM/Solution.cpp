// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
   
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int l = i-1;
            int r = i-1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if (dp[l] != -1) {
                    dp[r+1] = (dp[r+1] == -1 ? dp[l]+1 : min(dp[r+1], dp[l]+1));
                }
                --l; ++r;
            }
            l = i-1;
            r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if (dp[l] != -1) {
                    dp[r+1] = (dp[r+1] == -1 ? dp[l]+1 : min(dp[r+1], dp[l]+1));
                }
                --l; ++r;
            }
        }
        for (int i : dp) cout << i << ' ';
        return dp[n]-1;
    }
};