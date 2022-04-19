// https://leetcode.com/problems/reverse-only-letters

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0;
        int n = s.length();
        int r = n-1;
        while(l < r) {
            if (!isalpha(s[l])) {
                ++l;
            } else if (!isalpha(s[r])) {
                --r;
            } else {
                swap(s[l++], s[r--]);
            }
        }
        return s;
    }
};