// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int f = find(s, ')'); 
        reverse(s.begin(), s.end()); 
        int b = find(s, '(');
        return max(f, b); 
    }
    
    
    int find(string& s, char fore) {
        int lvl = 0; 
        int sz = 0; 
        int ans = 0; 
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == fore) {
                --lvl; 
            } else {
                ++lvl; 
            }
            ++sz;
            if (lvl == 0) {
                ans = max(ans, sz); 
            }
            if (lvl < 0) {
                lvl = 0; 
                sz = 0; 
            }
        }
        return ans; 
    }
};