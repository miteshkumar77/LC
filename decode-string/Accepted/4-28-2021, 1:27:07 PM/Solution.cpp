// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        stack<string> strs;
        strs.push("");
        stack<int> ct;
        ct.push(1);
        int mult = 1;
        string num = "";
        for (char c : s) {
            if (isdigit(c)) {
                num.push_back(c);
                continue;
            } else {
                mult = 1;
                if (num.length() > 0) {
                    mult = stoi(num);
                    num = "";
                }
            }
            if (c == '[') {
                strs.push("");
                ct.push(mult);
            } else if (c == ']') {
                string s = strs.top();
                strs.pop();
                for (int i = 0; i < ct.top(); ++i) {
                    strs.top() += s;
                }
                ct.pop();
            } else {
                strs.top().push_back(c);
            }
        }
        
        return strs.top();
        
    }
};