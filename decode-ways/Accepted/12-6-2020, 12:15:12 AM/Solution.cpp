// https://leetcode.com/problems/decode-ways

class Solution {
public:
    
    inline int conv(char a, char b) {
        return (a - '0') * 10 + (b - '0'); 
    }
    
    int numDecodings(string s) {
        int n = s.length(); 
        if (s[0] == '0') return 0;
        int dp2 = 1;
        int dp1 = 1;
        
        for (int i = 1; i < n; ++i) {
            int cur;
            if (s[i] == '0') {
                if (s[i-1] == '0') {
                    return 0;
                }
                
                if (conv(s[i - 1], s[i]) > 26) {
                    return 0;
                }
                
                cur = dp2;
            } else {
                cur = dp1; 
                if (s[i - 1] != '0' && conv(s[i - 1], s[i]) <= 26) {
                    cur += dp2;
                }
            }
            dp2 = dp1;
            dp1 = cur;
        }
        
        return dp1;
        
        
    }
};