// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int t2,t1;
        bool ok;
        for (const string& s : tokens) {
            ok = false;
            for (char c : s) {
                if (isdigit(c)) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                stk.push(stoi(s));
            } else {
                t2 = stk.top(); stk.pop();
                t1 = stk.top(); stk.pop();
                if (s == "+") {
                    stk.push(t1 + t2);
                } else if (s == "-") {
                    stk.push(t1 - t2);
                } else if (s == "*") {
                    stk.push(t1 * t2);
                } else if (s == "/") {
                    stk.push(t1 / t2);
                }
            }
        }
        return stk.top();
    }
};