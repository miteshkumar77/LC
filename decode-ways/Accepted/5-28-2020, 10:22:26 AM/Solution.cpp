// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0; 
        }
        
        int n = s.length(); 
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1; 
        dp[1] = 1; 
        string tmp = ""; 
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == '0' && (s[i - 2] == '0' || (s[i - 2] - '0') > 2)) {
                return 0; 
            }
            tmp = ""; 
            tmp += s[i - 2]; 
            tmp += s[i - 1]; 
            
            if (stoi(tmp) <= 26) {
                dp[i] += dp[i - 2]; 
            }
            
            if (s[i - 1] != '0' && s[i - 2] != '0') {
                dp[i] += dp[i - 1]; 
            }
            
        }
        
        return dp[n]; 
        
        
    }
};




// if (s[0] == '0') {
//             return 0; 
//         }
//         int n = s.length(); 
//         vector<int> dp(s.length() + 1, 0); 
//         dp[0] = 1; 
//         string tmp = ""; 
//         for (int i = 2; i <= n; ++i) {
//             tmp = ""; 
//             tmp += s[i - 2]; 
//             tmp += s[i - 1]; 
//             if (s[i - 1] == '0' && (s[i - 2] == '0' || (s[i - 2] - '0') > 2)) {
//                 return 0; 
//             }
            
//             if (stoi(tmp) <= 26) {
//                 dp[i] += dp[i - 2]; 
//             }
            
//             dp[i] += dp[i - 1]; 
//         }
        
//         return dp.back(); 