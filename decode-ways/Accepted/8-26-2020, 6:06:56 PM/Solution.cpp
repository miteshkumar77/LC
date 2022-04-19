// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        
        if (s[0] == '0') {
            return 0; 
        }
        
        
        vector<int> dp(s.length() + 1); 
        dp[0] = 1; 
        dp[1] = 1; 
        
        for (int i = 2; i <= s.length(); ++i) {
            if (s[i - 1] == '0' && s[i - 2] == '0') {
                return 0; 
            }
            
            if (s[i - 1] == '0' && s[i - 2] > '2') {
                return 0; 
            }
            
            dp[i] = 0; 
            
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1]; 
            }
            
            if ((s[i - 2] != '0') && 10 * (s[i - 2] - '0') + s[i - 1] - '0' <= 26) {
                dp[i] += dp[i - 2]; 
            }
        }
        
        return dp.back(); 
        
        
    }
};




