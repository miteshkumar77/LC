// https://leetcode.com/problems/to-lower-case

class Solution {
public:
    string toLowerCase(string s) {
        int n = s.length();
        for (int i = 0; i < n; ++i) s[i] = isalpha(s[i]) ? tolower(s[i]) : s[i];
        return s;
    }
};