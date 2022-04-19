// https://leetcode.com/problems/consecutive-characters

class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int len = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                ++len;
                ans = max(ans, len);
            } else {
                len = 1;
            }
        }
        return ans;
        
    }
};