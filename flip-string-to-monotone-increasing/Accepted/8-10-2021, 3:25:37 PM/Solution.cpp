// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int zeroes = 0;
        for (char c : s) zeroes += (c == '0');
        int ans = INT_MAX;
        int ones = 0;
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, ones + zeroes);
            if (i < n) {
                ones += (s[i] == '1');
                zeroes -= (s[i] == '0');
            }
        }
        return ans;
    }
};