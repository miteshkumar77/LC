// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.length() + 1, vector<bool>(s.length() + 1, false)); 
        dp[0][0] = true; 
        
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i - 1][0] && p[i - 1] == '*') {
                dp[i][0] = true; 
            }
        }
        for (int i = 1; i <= p.length(); ++i) {
            for (int j = 1; j <= s.length(); ++j) {
                if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1]; 
                } else if (p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; 
                } else if (p[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; 
                }
            }
        }
        return dp.back().back();
                     
        
    }
};