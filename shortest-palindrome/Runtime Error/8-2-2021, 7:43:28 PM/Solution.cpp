// https://leetcode.com/problems/shortest-palindrome

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        vector<int> lps(n);
        lps[0] = 0;
        int j = 0;
        for (int i = 1; i < n;) {
            if (s[i] == s[j]) {
                lps[i++] = ++j;
            } else if (j > 0) {
                j = lps[j-1];
            } else {
                lps[i++] = 0;
            }
        }
        j = 0;
        int maxj = 0;
        for (int i = n-1; i >= 0;) {
            if (s[i] == s[j]) {
                ++j;
                --i;
            } else if (j > 0) {
                j = lps[j-1];
            } else {
                --i;
            }
            if (i <= j) {
                maxj = max(maxj, j);
            }
        }
        auto add = s.substr(j);
        reverse(s.begin(), s.end());
        
        return s + add;
    }
};