// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int ansL = 0;
        int ansR = -1; 
        int L; 
        int R; 
        for (int i = 0; i < s.size(); ++i) {
            L = i; 
            R = i; 
            while(L >= 0 && R < s.size() && s[L] == s[R]) {
                --L;
                ++R;
            }
            if (R - L - 2 > ansR - ansL) {
                ansR = R - 1; 
                ansL = L + 1; 
            }
        }
        
        for (int i = 1; i < s.size(); ++i) {
            L = i - 1; 
            R = i; 
            while(L >= 0 && R < s.size() && s[L] == s[R]) {
                --L;
                ++R;
            }
            
            if (R - L - 2 > ansR - ansL) {
                ansR = R - 1; 
                ansL = L + 1; 
            }
        }
        
        string ans = ""; 
        for (int i = ansL; i <= ansR; ++i) {
            ans += s[i]; 
        }
        return ans; 
    }
};