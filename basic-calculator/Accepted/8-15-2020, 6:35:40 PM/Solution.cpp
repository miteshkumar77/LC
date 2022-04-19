// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    int calculate(string s) {
        
        stack<int> ans; 
        stack<int> sgn; 
        ans.push(0); 
        sgn.push(1); 
        
        int c_sgn = 1;
        string num = "0"; 
        for (char c : s) {
            
            if (c == ' ') {
                continue; 
            }
            
            if (c == '(') {
                sgn.push(c_sgn); 
                ans.push(0); 
                c_sgn = 1; 
                num = "0"; 
            } else if (c == ')') {
                ans.top() += stoi(num) * c_sgn; 
                num = "0"; 
                int p_sgn = sgn.top(); sgn.pop(); 
                int res = ans.top(); ans.pop(); 
                ans.top() += p_sgn * res; 
            } else if (c == '+' || c == '-') {
                
                ans.top() += stoi(num) * c_sgn; 
                c_sgn = (c == '+')?1:(-1); 
                num = "0"; 
            } else {
                num += c; 
            }
        }
        ans.top() += stoi(num) * c_sgn; 
        return ans.top(); 
        
    }
};