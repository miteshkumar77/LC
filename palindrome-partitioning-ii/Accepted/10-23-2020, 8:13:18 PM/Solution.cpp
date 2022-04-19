// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    int minCut(string s) {
        function<bool(int,int)> isPal = [&](int i, int j) -> bool {
            while(i < j) {
                if (s[i++] != s[j--]) {
                    return false;
                }
            }    
            
            return true;
        };
        int n = s.length();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        s = '#' + s;
        for (int i = 0; i <= n; ++i) {
            if (dp[i] != INT_MAX) {
                for (int j = i + 1; j <= n; ++j) {
                    if (isPal(i + 1, j)) {
                        dp[j] = min(dp[j], dp[i] + 1);
                    }
                }
            }
        }
        
        
        return dp.back() - 1;
        
        
    }
};