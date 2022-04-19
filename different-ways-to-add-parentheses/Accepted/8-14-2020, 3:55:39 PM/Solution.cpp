// https://leetcode.com/problems/different-ways-to-add-parentheses

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        
        function<vector<int>(string)> bt = [&](string exp) -> vector<int> {
            vector<int> result; 
            for (int i = 0; i < exp.length(); ++i) {
                if (exp[i] == '-' || exp[i] == '+' || exp[i] == '*') {
                    vector<int> left = bt(exp.substr(0, i));
                    vector<int> right = bt(exp.substr(i + 1));
                    for (int l : left) {
                        for (int r : right) {
                            if (exp[i] == '-') {
                                result.push_back(l - r); 
                            } else if (exp[i] == '+') {
                                result.push_back(l + r); 
                            } else {
                                result.push_back(l * r); 
                            }
                        }
                    }
                }
            }
            if (result.size() == 0) {
                result.push_back(stoi(exp)); 
            }
            return result; 
        }; 
        return bt(input); 
    }
};