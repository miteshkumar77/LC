// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.length() + 1, vector<int>(s.length() + 1, -1)); 
        function<int(int,int)> bt = [&](int sptr, int tptr) -> int {
            if (sptr < tptr) {
                return 0; 
            }
            
            if (tptr == 0) {
                return 1; 
            }
            
            if (sptr == 0) {
                return 0; 
            }
            
            if (dp[tptr][sptr] != -1) {
                return dp[tptr][sptr]; 
            }
            int ans = 0; 
            if (s[sptr - 1] == t[tptr - 1]) {
                ans += bt(sptr - 1, tptr - 1); 
            }
            ans += bt(sptr - 1, tptr); 
            dp[tptr][sptr] = ans; 
            return ans; 
        };
        return bt(s.length(), t.length()); 
    }
};