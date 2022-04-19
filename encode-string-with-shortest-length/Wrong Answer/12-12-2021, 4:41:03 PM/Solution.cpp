// https://leetcode.com/problems/encode-string-with-shortest-length

class Solution {
public:
    
    bool can_compress(int l, int r, int k, string const& s) {
        if ((r - l + 1) % k != 0) {
            return false; 
        }
        for (int x = 1; x < (r - l + 1)/k; ++x) {
            if (s.substr(l, k) != s.substr(l + k * x, k)) {
                return false;
            }
        }
        return true;
    }
    string const& solve(int l, int r, string const& s, vector<vector<string>>& dp) {
        if (dp[l][r].length() == 0) {
            dp[l][r] = s.substr(l, r - l + 1);
            for (int x = 1; x < (r - l + 1); ++x) {
                if (can_compress(l, r, x, s)) {
                    string tmp = to_string((r - l + 1)/x) + "[" + 
                        s.substr(l, x) + "]";
                    if (tmp.length() < dp[l][r].length()) {
                        dp[l][r].swap(tmp);
                    }
                }
            }
            for (int x = l+1; x < r; ++x) {
                auto sl = solve(l, x, s, dp);
                auto sr = solve(x+1, r, s, dp);
                if (sl.length() + sr.length() <= dp[l][r].length()) {
                    dp[l][r] = sl + sr;
                }
            }
        }
        return dp[l][r];
    }
    string encode(string s) {
        int n = s.length();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for (int l = 0; l < n; ++l) {
            dp[l][l] = s.substr(l, 1);
        }
        return solve(0, s.length()-1, s, dp);
        
    }
};