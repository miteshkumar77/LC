// https://leetcode.com/problems/score-of-parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0);
        char prev = '_';
        for (char c : s) {
            if (c == ')') {
                if (prev == '(') {
                    stk.top() += 1;
                } else {
                    stk.top() *= 2;
                }
                int tmp = stk.top();
                stk.pop();
                stk.top() += tmp;
            } else {
                stk.push(0);
            }
            prev = c;
        }
        // ( ( ) )
        // 2
        int ans = 0;
        while(!stk.empty()) {
            ans += stk.top(); stk.pop();
        }
        return ans;
    }
};