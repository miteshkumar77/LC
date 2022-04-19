// https://leetcode.com/problems/longest-happy-prefix

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        int j = n-1;
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == s[j]) {
                --j;
            } else {
                j = n-1;
                if (s[i] == s[j]) --j;
            }
        }
        return s.substr(j+1);
    }
};