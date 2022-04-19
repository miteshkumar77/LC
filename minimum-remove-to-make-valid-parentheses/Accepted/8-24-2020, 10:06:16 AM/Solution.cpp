// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int ctr = 0; 
        vector<bool> contains(s.length(), true); 
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++ctr; 
            } else if (s[i] == ')') {
                --ctr; 
            }
            
            if (ctr == -1) {
                contains[i] = false; 
                ctr = 0; 
            }
        }
        
        int i = s.length() - 1; 
        
        while(i >= 0 && ctr > 0) {
            if (s[i] == '(') {
                contains[i] = false;
                --ctr; 
            }
            --i; 
        }
        
        string ans = ""; 
        
        for (int i = 0; i < s.length(); ++i) {
            if (contains[i]) {
                ans += s[i]; 
            }
        }
        return ans; 
    }
};