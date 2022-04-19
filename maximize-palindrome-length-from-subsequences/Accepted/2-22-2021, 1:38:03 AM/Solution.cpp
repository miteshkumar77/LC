// https://leetcode.com/problems/maximize-palindrome-length-from-subsequences

class Solution {
public:
    
    int sol(vector<vector<int>>& dp, int l, int r, const string& w) {
        if (l == r) return 1;
        if (r < l) return 0;
        
        if (dp[l][r] != -1) return dp[l][r];
        
        if (w[l] == w[r]) {
            dp[l][r] = sol(dp, l + 1, r - 1, w) + 2;
        }
        dp[l][r] = max(dp[l][r], max(sol(dp, l + 1, r, w), sol(dp, l, r - 1, w))); 
        return dp[l][r];
    }
    int longestPalindrome(string word1, string word2) {
        int n = word1.size();
        int m = word2.size(); 
        
        string total = word1 + word2;
        vector<vector<int>> dp(n + m, vector<int>(n + m, -1)); 
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (word1[i] == word2[j]) {
                    ans = max(ans, 2 + sol(dp, i + 1, j + n - 1, total)); 
                }
            }
        }
        return ans;
        
    }
};