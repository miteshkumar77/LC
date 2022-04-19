// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
        
        
        // int L = 0; 
        // int R = s.length() - 1; 
        function<bool(int,int,bool)> ispal = [&](int L, int R, bool skipped) -> bool {
            while(L < R) {
                if (s[L] != s[R]) {
                    if (skipped) {
                        return false; 
                    }
                    return ispal(L + 1, R, true) || ispal(L, R - 1, true); 
                } else {
                    ++L; 
                    --R; 
                }
            }
            return true; 
        };
        
        return ispal(0, s.length() - 1, false); 
    }
};