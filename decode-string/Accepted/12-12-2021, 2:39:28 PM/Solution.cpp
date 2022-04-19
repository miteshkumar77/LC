// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        stack<int> mult;        
        stack<string> rep;
        mult.push(1);
        rep.push("");
        int cm = 0;
        for (char c : s) {
            if ('0' <= c && c <= '9') {
                cm = (cm * 10) + (c - '0');
            } else if (c == '[') {
                cm = max(cm, 1);
                mult.push(cm);
                cm = 0;
                rep.push("");
            } else if (c == ']') {
                int d = mult.top(); mult.pop();
                string dup = rep.top(); rep.pop();
                for (; d--;) {
                    rep.top() += dup;
                }
            } else {
                rep.top().push_back(c);
            }
        }
        return rep.top();
    }
    
    
    
    
};