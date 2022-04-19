// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
        
        
        
        bool skipped = false; 
        bool found = true; 
        
        int i = 0; 
        int j = s.length() - 1; 
        
        while(i < j) {
            if (s[i] != s[j]) {
                --j;
                if (skipped) {
                    found = false;
                    break;
                } else {
                    skipped = true; 
                }
            } else {
                --j;
                ++i; 
            }
        }
        
        if (found) {
            return true; 
        }
        i = 0; 
        j = s.length() - 1; 
        found = true; 
        skipped = false;
        while(i < j) {
            if (s[i] != s[j]) {
                ++i; 
                if (skipped) {
                    found = false; 
                    break;
                } else {
                    skipped = true; 
                }
            } else {
                --j;
                ++i;
            }
        }
        
        if (found) {
            return true;
        }
        return false; 
        
    }
};