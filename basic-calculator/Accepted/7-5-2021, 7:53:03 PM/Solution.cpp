// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    pair<int,int> calc(string s, int idx) {
        int n = s.length();
        int sign = 1;
        int total = 0;
        for (int i = idx; i < n; ++i) {
            if (s[i] == '(') {
                auto p = calc(s, i+1);
                i = p.first;
                total += sign * p.second;
                sign = 1;
            } else if (s[i] == ')') {
                return {i, total};
            } else if (s[i] == '-') {
                sign *= -1;
            } else if (s[i] == ' ') {
                continue;
            } else if (isalnum(s[i])) {
                string arg = "";
                while(i < n && isdigit(s[i])) {
                    arg.push_back(s[i++]);
                }
                --i;
                total += sign * stoi(arg);
                sign = 1;
            }
        }
        return {n, total};
    }
    
    int calculate(string s) {
        return calc(s, 0).second;
    }
};