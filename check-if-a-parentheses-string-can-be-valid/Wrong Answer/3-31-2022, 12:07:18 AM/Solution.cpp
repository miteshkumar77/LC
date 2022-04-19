// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int ct = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (locked[i] == 1) {
                if ((ct += (s[i] == '(' ? 1 : -1)) < 0) {
                    return false;
                }
            } else {
                if (ct == 0) {
                    ++ct;
                } else {
                    --ct;
                }
            }
        }
        return ct == 0;
    }
};