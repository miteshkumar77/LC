// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res; 
        string s = ""; 
        generator(res, s, 0, n); 
        return res; 
    }
    
    void generator(vector<string>& ans, string& s, int open_parenthesis, int n) {
        if (s.size() == 2*n) {
            ans.push_back(s); 
        }
        
        int closed_parenthesis = s.length() - open_parenthesis; 
        
        if (open_parenthesis < n) {
            s += '(';
            generator(ans, s, open_parenthesis + 1, n); 
            s.pop_back(); 
        }
        
        if (closed_parenthesis < open_parenthesis) {
            s += ')';
            generator(ans, s, open_parenthesis, n); 
            s.pop_back(); 
        }
    }
};

