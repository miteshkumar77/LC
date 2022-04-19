// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s; 
        bt(0, 2 * n, ans, s);
        return ans; 
    }
    
    void bt(int open, int n, vector<string>& ans, string& box) {
        if (box.length() == n) {
            ans.push_back(box); 
            return; 
        }
        if (open + 1 <= n - box.length() - 1) {
            box.push_back('(');
            bt(open + 1, n, ans, box); 
            box.pop_back(); 
        }
        
        if (open > 0) {
            box.push_back(')');
            bt(open - 1, n, ans, box); 
            box.pop_back(); 
        }
    }
};