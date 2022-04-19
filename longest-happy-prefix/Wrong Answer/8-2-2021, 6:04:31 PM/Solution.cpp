// https://leetcode.com/problems/longest-happy-prefix

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n);
        lps[0] = 0;
        int j = 0;
        int i = 1;
        while (i < n) {
            if (j >= 0 && s[i] == s[j]) {
                lps[i++] = ++j;
            } else if (j > 0) {
                j = lps[j]-1;
            } else {
                j = 0;
                lps[i++] = 0;
            }
        }
        return s.substr(0, lps[n-1]);
    }
};