// https://leetcode.com/problems/count-sorted-vowel-strings

class Solution {
public:
    int countVowelStrings(int n) {
        array<int, 5> vwls{'a', 'e', 'i', 'o', 'u'}; 
        vector<vector<int>> dp(5, vector<int>(n, 1));
        
        
        for (int c = 1; c < n; ++c) {
            for (int v = 0; v < 5; ++v) {
                dp[v][c] = 0;
                if  (v != 0) dp[v][c] += dp[v - 1][c];
                dp[v][c] += dp[v][c - 1];
            }
        }
        int ans = 0;
        for (int v = 0; v < 5; ++v) ans += dp[v].back();
        return ans;
    }
};