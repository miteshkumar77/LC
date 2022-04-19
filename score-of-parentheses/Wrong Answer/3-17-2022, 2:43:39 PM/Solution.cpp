// https://leetcode.com/problems/score-of-parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        char prev = '_';
        for (char c : s) {
            if (c == ')') {
                if (prev == '(') {
                    stk.top() += 1;
                } else {
                    int tmp = stk.top() * 2;
                    stk.pop(); stk.top() += tmp;
                }
            } else {
                stk.push(0);
            }
            prev = c;
        }
        // ( ( ) )
      // 0     1
        int ans = 0;
        while(!stk.empty()) {
            ans += stk.top(); stk.pop();
        }
        return ans;
    }
};