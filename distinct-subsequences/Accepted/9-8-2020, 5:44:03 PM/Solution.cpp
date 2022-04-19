// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long int>> dp(t.length() + 1, vector<unsigned long long int>(s.length() + 1, 0)); 
        // s : large
        // t : small
        
        for (int sptr = 0; sptr < s.length(); ++sptr) {
            dp[0][sptr] = 1; 
        }
        
        for (int tptr = 1; tptr <= t.length(); ++tptr) {
            for (int sptr = tptr; sptr <= s.length(); ++sptr) {
                if (s[sptr - 1] == t[tptr - 1]) {
                    dp[tptr][sptr] += dp[tptr - 1][sptr - 1]; 
                }
                dp[tptr][sptr] += dp[tptr][sptr - 1]; 
            }
        }
        return dp.back().back(); 
    }
};