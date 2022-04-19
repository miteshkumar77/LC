// https://leetcode.com/problems/break-a-palindrome

class Solution {
public:
    string breakPalindrome(string s) {
        if (s.length() == 1) return "";
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
        }
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == 'a') {
                s[i] = 'b';
                return s;
            }
        }
        return s;
    }
};