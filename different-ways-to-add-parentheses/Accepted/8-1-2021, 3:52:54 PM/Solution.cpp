// https://leetcode.com/problems/different-ways-to-add-parentheses

class Solution {
public:
    using ll = long long;
    bool isop(char c) {
        return c == '+' || c == '-' || c == '*';
    }
    
    ll apply_op(int a, int b, char c) {
        if (c == '+') return a + b;
        if (c == '-') return a - b;
        return a * b;
    }
    
    vector<int> const& solve(string const& exp, int l, int r, vector<vector<vector<int>>>& dp, vector<vector<bool>>& seen) {
        if (seen[l][r]) return dp[l][r];
        int op_count = 0;
        for (int i = l; i <= r; ++i) {
            if (isop(exp[i])) {
                auto lr = solve(exp, l, i-1, dp, seen);
                auto rr = solve(exp, i+1, r, dp, seen);
                for (int x : lr) {
                    for (int y : rr) {
                        dp[l][r].push_back(apply_op(x, y, exp[i]));
                    }
                }
                ++op_count;
            }
        }
        seen[l][r] = true;
        if (op_count == 0) {
            dp[l][r].push_back(stoi(exp.substr(l, r - l + 1)));
        }
        return dp[l][r];
    }
    
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        return solve(expression, 0, n-1, dp, seen);
    }
};