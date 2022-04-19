// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        array<char, 256> mp;
        mp['['] = 0;
        mp['{'] = 0;
        mp['('] = 0;
        mp[']'] = '[';
        mp[')'] = '(';
        mp['}'] = '{';
        
        stack<char> stk;
        for (char c : s) {
            if (mp[c] == 0) {
                stk.push(c);
            } else {
                if (stk.empty() || stk.top() != mp[c]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};