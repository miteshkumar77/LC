// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 0;
        int other = 0;
        int ans = 0;
        int n = s.length();
        int i = 0;
        while(i < n) {
            do {
                ++i;
                ++cur;
            }while(i < n && (i == 0 || s[i] == s[i - 1]));
            ans += min(cur, other);
            other = cur;
            cur = 0;
        }
        return ans;
    }
};