// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        function<bool(int,int)> isPal = [&](int l, int r) -> bool {
            while(l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        };
        
        
        vector<vector<vector<string>>> dp(n + 1, vector<vector<string>>()); 
        dp[0].push_back(vector<string>());
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (isPal(j, i)) {
                    for (auto v : dp[j]) {
                        dp[i + 1].push_back(v);
                        dp[i + 1].back().push_back(s.substr(j, i - j + 1));
                    }
                }
            }
        }
        
        return dp.back();
        
    }
};