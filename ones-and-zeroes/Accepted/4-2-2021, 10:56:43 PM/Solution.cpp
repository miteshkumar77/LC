// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> ones(strs.size(), 0);
        vector<int> zeroes(strs.size(), 0);
        for (int i = 0; i < strs.size(); ++i) {
            for (char c : strs[i]) {
                if (c == '0') {
                    ++zeroes[i];    
                } else {
                    ++ones[i];
                }
            }
        }    
        int ans = 0; 
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        dp[0][0] = 0;
        for (int c = 0; c < strs.size(); ++c) {
            for (int i = m; i >= 0; --i) {
               for (int j = n; j >= 0; --j) {
                   if (i >= zeroes[c] && j >= ones[c] && dp[i - zeroes[c]][j - ones[c]] != -1) {
                       dp[i][j] = max(dp[i][j], dp[i - zeroes[c]][j - ones[c]] + 1);
                       ans = max(ans, dp[i][j]);
                   }             
               } 
            }
        }
        return ans;
    }
};