// https://leetcode.com/problems/basic-calculator-ii

class Solution {
public:
    int tokens(string s) {
        vector<string> ans;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
                ans.push_back(string(1, s[i]));
            } else if (s[i] == ' ') {
                continue;
            } else {
                ans.push_back("");
                while(isdigit(s[i])) {
                    ans.back().push_back(s[i++]);
                }
                --i;
            }
        }
        
        vector<string> ans2;
        for (string const & a : ans) {
            bool push = true;
            if (isdigit(a[0])) {
                if (ans2.size() > 1) {
                    if (ans2.back() == "*") {
                        ans2.pop_back();
                        ans2.back() = to_string(stoi(ans2.back()) * stoi(a));
                        push = false;
                    } else if (ans2.back() == "/") {
                        ans2.pop_back();
                        ans2.back() = to_string(stoi(ans2.back()) / stoi(a));
                        push = false;
                    }
                }
            }
            if (push) {
                ans2.push_back(a);
            }
        }
        //for (string & s : ans2) cout << s << ' ';
        //cout << endl;
        int ret = 0;
        int sign = 1;
        for (string const & a : ans2) {
            if (a == "-") {
                sign = sign * -1;
            } else if (isdigit(a[0])) {
                //cout << ret << ' ' << a;
                //cout << endl;
                ret += sign * stoi(a);
                sign = 1;
            }
        }
        return ret;
        
    }
    
    int calculate(string s) {
        return tokens(s);
    }
};