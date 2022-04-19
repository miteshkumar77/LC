// https://leetcode.com/problems/repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int j = 0; 
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[j]) {
                ++j; 
            } else {
                j = 0; 
                if (s[i] == s[j]) {
                    ++j; 
                } else {
                    if (i >= s.length()/2) {
                        return false; 
                    }
                }
            }
            
            if (i >= s.length()/2 && s.length() % (i - j + 1) != 0) {
                return false; 
            }
        }
        return true; 
    }
};