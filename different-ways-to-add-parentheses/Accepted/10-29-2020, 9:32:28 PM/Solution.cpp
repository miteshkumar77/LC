// https://leetcode.com/problems/different-ways-to-add-parentheses

class Solution {
public:
    
    
    bool is_number(string s) {
        int i = -1;
        for (char c : s) {
            ++i;
            if (i == 0 && c == '-') continue;
            if (c != ' ' && !isdigit(c)) {
                return false;
            }
        }
        return true;
    }
    
    
    vector<int> diffWaysToCompute(string input) {
        int n = input.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        
        vector<int> ans;
        function<void(int,int)> calc = [&](int l, int r) -> void {
            
            
            if (dp[l][r].size() != 0) {
                return;
            }
            
            
            if (is_number(input.substr(l, r - l + 1))) {
                dp[l][r].push_back(stoi(input.substr(l, r - l + 1))); 

                return;
            } else {
                for (int i = l; i <= r; ++i) {
                    if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                        calc(l, i - 1);
                        calc(i + 1, r);
                        for (auto a : dp[l][i - 1]) {
                            for (auto b : dp[i + 1][r]) {
                                if (input[i] == '+') {
                                    dp[l][r].push_back(a + b);
                                } else if (input[i] == '-') {
                                    dp[l][r].push_back(a - b);
                                } else {
                                    dp[l][r].push_back(a * b);
                                }
                            }
                        }
                    }
                }
            }
        };
        
        calc(0, input.length() - 1);
        
        return dp[0][n - 1]; 
    }
};