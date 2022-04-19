// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int left = 0;
        for (char c : s) {
            left += (c == ')'); 
        }
        int opens = 0;
        for (char c : s) {
            if (c == '(') {
                ++opens;
            } else if (c == ')') {
                --opens;
                --left;
            }
            if (opens == -1) {
                opens = 0;
            } else {
                if (c == '(' && opens > left) {
                    --opens;
                } else {
                    ans.push_back(c); 
                }
            }
        }
        return ans;
    }
};