// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    int calculate(string s) {
        
        function<array<int, 2>(int)> eval = [&](int j) -> array<int, 2> {
            int ans = 0; 
            int sgn = 1; 
            string num = "0"; 
            for (int i = j; i < s.length(); ++i) {
                if (s[i] == '(') {
                    array<int, 2> res = eval(i + 1); 
                    ans += sgn * res[0]; 
                    i = res[1]; 
                } else if (s[i] == ')') {
                    // cout << ans << endl; 
                    ans += stoi(num) * sgn; 
                    return array<int, 2>{ans, i};
                } else if (s[i] == '+' || s[i] == '-') {
                    // cout << "n1: " << num << endl; 
                    ans += stoi(num) * sgn; 
                    if (s[i] == '+') {
                        sgn = 1; 
                    } else {
                        sgn = -1; 
                    }
                    num = "0"; 
                } else {
                    num += s[i]; 
                }
            }
            // cout << "n2: " << num << endl; 
            // cout << ans << endl; 
            ans += sgn * stoi(num); 
            return array<int, 2>{ans, (int)s.length() - 1}; 
        };
        
        return eval(0)[0]; 
    }
};