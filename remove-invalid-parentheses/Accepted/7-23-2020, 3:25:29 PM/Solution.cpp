// https://leetcode.com/problems/remove-invalid-parentheses

class Solution {
public:
    array<char, 2> par{'(', ')'};
    array<char, 2> rpar{')', '('};
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans; 
        generator(s, ans, par, 0, 0);
        return ans; 
    }
    
    
    void generator(string s, vector<string>& ans, array<char, 2> par, int last_i, int last_j) {
        int t = 0;
        for (int i = last_i; i < s.length(); ++i) {
            if (s[i] == par[0]) {
                ++t; 
            } else if (s[i] == par[1]) {
                --t; 
            }
            
            if (t < 0) {
                for (int j = last_j; j <= i; ++j) {
                    if (s[j] == par[1] && (j == last_j || s[j] != s[j - 1])) {
                        generator(s.substr(0, j) + s.substr(j + 1, s.length() - j - 1), ans, par, i, j); 
                    }
                }
                return; 
            }
            
        }
        string reversed = s;
        reverse(reversed.begin(), reversed.end()); 
        if (par[0] == '(') {
            generator(reversed, ans, rpar, 0, 0);
        } else {
            ans.push_back(reversed); 
        }
    }
};