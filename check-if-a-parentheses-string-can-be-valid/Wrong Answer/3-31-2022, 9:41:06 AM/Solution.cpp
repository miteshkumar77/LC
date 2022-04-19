// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 == 1) return false;
        int left_needed = n/2; int right_needed = n/2;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') --left_needed;
                else --right_needed;
            }
        }
        int ct = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                ct += (s[i] == '(' ? 1 : -1);
            } else if (left_needed) {
                --left_needed;
                ++ct;
            } else if (right_needed) {
                --right_needed;
                --ct;
            }
        }
        return ct == 0;
    }
};