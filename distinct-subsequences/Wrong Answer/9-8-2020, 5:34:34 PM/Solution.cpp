// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.length() + 1, vector<int>(s.length() + 1, 0)); 
        dp[0][0] = 1; 
        for (int tptr = 1; tptr <= t.length(); ++tptr) {
            for (int sptr = 1; sptr <= s.length(); ++sptr) {
                if (s[sptr - 1] == t[tptr - 1]) {
                    dp[tptr][sptr] += dp[tptr - 1][sptr - 1]; 
                }
                dp[tptr][sptr] += dp[tptr][sptr - 1]; 
            }
        }
        return dp.back().back(); 
    }
};