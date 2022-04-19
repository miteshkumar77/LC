// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int zeros = 0;
        int ones = 0;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ones += s[i] == '0';
        }
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, zeros + ones); 
            if (i == n) continue;
            zeros += s[i] == '1';
            ones -= s[i] == '0';
        }
        return ans;
    }
};