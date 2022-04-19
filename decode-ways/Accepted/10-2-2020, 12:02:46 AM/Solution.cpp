// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        
        int n = s.length();
        // vector<int> dp(n + 1); dp[0] = 1;
        
        int pre0 = 1;
        int pre1 = 1;
        
        
        for (int i = 2; i <= s.length(); ++i) {
            int cur = s[i - 1] - '0';
            int pre = s[i - 2] - '0';
            int dpi = 0;
            if (cur == 0) {
                
                if (pre == 0) {
                    return 0;
                }
                
                if (pre * 10 + cur > 26) {
                    return 0;
                }
                
                dpi = pre0;
                
            } else {
                dpi = pre1;
                if (pre != 0 && pre * 10 + cur <= 26) {
                    dpi += pre0;
                }
            }
            pre0 = pre1;
            pre1 = dpi;
        }
        
        return pre1;
        
    }
};