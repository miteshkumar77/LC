// https://leetcode.com/problems/count-vowels-permutation

class Solution {
public:
    int countVowelPermutation(int n) {
        int M = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        dp[0]['a'-'a'] = 1; dp[0]['e'-'a'] = 1; dp[0]['i'-'a'] = 1; dp[0]['o'-'a'] = 1; dp[0]['u'-'a'] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i]['a'-'a'] = ((dp[i-1]['e'-'a'] + dp[i-1]['u'-'a']) % M + dp[i-1]['i'-'a']) % M;
            dp[i]['e'-'a'] = (dp[i-1]['a'-'a'] + dp[i-1]['i'-'a']) % M;
            dp[i]['i'-'a'] = (dp[i-1]['e'-'a'] + dp[i-1]['o'-'a']) % M;
            dp[i]['o'-'a'] = dp[i-1]['i'-'a'];
            dp[i]['u'-'a'] = (dp[i-1]['o'-'a'] + dp[i-1]['i'-'a']) % M;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + dp[n-1][i]) % M;
        }
        return ans;
    }
};