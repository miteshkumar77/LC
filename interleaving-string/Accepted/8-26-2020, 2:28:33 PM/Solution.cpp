// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false; 
        }
        
        vector<vector<vector<int>>> dpv(s1.length(), vector<vector<int>>(s2.length(), vector<int>(s3.length(), -1))); 
        
        function<bool(int,int,int)> dp = [&](int c1, int c2, int c3) -> bool {
            
            
            
            if (c3 == s3.length()) {
                return true; 
            }
            
            if (c1 < s1.length() && c2 < s2.length()) {
                if (dpv[c1][c2][c3] != -1) {
                    return dpv[c1][c2][c3] == 1; 
                }
            }
            
            
            bool b = false; 

            if (c1 != s1.length() && s1[c1] == s3[c3]) {
                b = dp(c1 + 1, c2, c3 + 1); 
            }
            
            if (!b && c2 != s2.length() && s2[c2] == s3[c3]) {
                b = dp(c1, c2 + 1, c3 + 1); 
            }
            
            if (c1 < s1.length() && c2 < s2.length()) {
                if (b) {
                    dpv[c1][c2][c3] = 1; 
                } else {
                    dpv[c1][c2][c3] = 7; 
                }
            }
            
            return b; 
        }; 
        
        return dp(0, 0, 0); 
    }
};