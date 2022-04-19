// https://leetcode.com/problems/score-of-parentheses

class Solution {
public:
    
    
    
    int scoreOfParentheses(string s) {
        int n = s.length(); 
        stack<int> score;
        score.push(0);
        stack<int> pos;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                pos.push(i);
                score.push(0);
            } else if (s[i] == ')') {
                int tidx = pos.top(); pos.pop();
                int tscr = score.top(); score.pop();
                if (tidx + 1 == i) {
                    ++tscr;
                } else {
                    tscr *= 2;
                }
                score.top() += tscr;
            }
        }
        return score.top(); 
    }
};