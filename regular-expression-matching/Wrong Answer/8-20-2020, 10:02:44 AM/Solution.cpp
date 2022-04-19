// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.length() + 1, vector<bool>(s.length() + 1, false)); 
        
        dp[0][0] = true; 
        
        for (int i = 1; i <= p.length(); ++i) {
            if (p[i - 1] == '*') {
                dp[i][0] = dp[i - 2][0]; 
            }
        }
        
        for (int i = 1; i <= p.length(); ++i) {
            for (int j = 1; j <= s.length(); ++j) {
                if (p[i - 1] == '.' || p[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; 
                } else if (p[i - 1] == '*') {
                    if (p[i - 2] == s[j - 1] && dp[i][j - 1]) {
                        dp[i][j] = true; 
                    } else if (dp[i - 2][j]) {
                        dp[i][j] = true; 
                    }
                }
            }
        }
        
        
        return dp.back().back(); 
        
        
    }
};