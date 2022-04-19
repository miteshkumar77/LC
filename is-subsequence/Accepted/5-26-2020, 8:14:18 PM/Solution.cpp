// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sptr = 0;  
        for (int tptr = 0; tptr < t.length(); ++tptr) {
            if (sptr == s.length()) {
                return true; 
            }
            if (s[sptr] == t[tptr]) {
                ++sptr; 
            }
            
        }
        
        return sptr == s.length(); 
    }
};