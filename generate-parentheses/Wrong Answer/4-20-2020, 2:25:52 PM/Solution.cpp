// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret = vector<string>(); 
        
        string s = "";
        string r = "";
        for (int i = 0; i < n; ++i) {
            s += '(';
            r += ')';
        }
        
        s += r; 
        
        // cout << s << endl; 
        ret.push_back(s); 
        gen(ret, s, 1); 
        return ret; 
    }
    
    
    void gen(vector<string>& perms, string& s, int i) {
        if (i == s.length() - 1) {
            return; 
        }
        
        if (s[i] == ')') {
            gen(perms, s, i + 1); 
            return; 
        }
        
        s[i] = ')'; 
        
        for (int k = i + 1; k < s.length() - 1; ++k) {
            if (s[k] == ')') {
                s[k] = '(';
                
                perms.push_back(s.substr(0, s.length())); 
                gen(perms, s, k + 1); 
                s[k] = ')'; 
            }
        }
        
        s[i] = '('; 
        
        gen(perms, s, i + 1); 
    }
};