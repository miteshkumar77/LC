// https://leetcode.com/problems/maximize-palindrome-length-from-subsequences

class Solution {
public:
    
    int sol(vector<vector<int>>& dp, const string& w1, const string& w2, int i, int j, int n, int m) {
        if (i == n || j == 0) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (w1[i] == w2[j]) {
            dp[i][j] = sol(dp, w1, w2, i + 1, j - 1, n, m) + 2;
        }
        dp[i][j] = max(dp[i][j], max(sol(dp, w1, w2, i + 1, j, n, m), sol(dp, w1, w2, i, j - 1, n, m))); 
        return dp[i][j];
    }
    int longestPalindrome(string word1, string word2) {
        int n = word1.size();
        int m = word2.size(); 
        vector<vector<int>> dp(n, vector<int>(m, -1)); 
        
        
        int ans = sol(dp, word1, word2, 0, m - 1, n, m); 
        if (ans < n + m) {
            ++ans;
        }
        return ans;
    }
};