// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int d = 0;
        for (char c : s) {
            if (c == '(') {
                ++d;
            } else if (c == ')') {
                --d;
            }
            ans = max(d, ans);
        }
        return ans;
    }
};