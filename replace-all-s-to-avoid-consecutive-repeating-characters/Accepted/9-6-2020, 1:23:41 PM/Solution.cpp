// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); ++i) {
            
            if (s[i] == '?') {
                char pre = '_'; 
                char nex = '_'; 
                if (i != 0) {
                    pre = s[i - 1]; 
                }
                if (i != s.length() - 1) {
                    nex = s[i + 1]; 
                }
                
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c != pre && c != nex) {
                        s[i] = c; 
                    }
                }
            }
            
        }
        return s; 
    }
    
    
    
    
    
};