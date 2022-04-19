// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<array<int, 2>> ct(N, {0,0});
        
        for (int i = 0; i < N; ++i) {
            for (char p : strs[i]) {
                ++ct[i][p - '0'];
            }
        }
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); 
        
        dp[0][0] = 0;
        int ans = 0;
        for (int s = 1; s <= N; ++s) {
            for (int z = m; z >= 0; --z) {
                for (int o = n; o >= 0; --o) {
                    if (z - ct[s - 1][0] >= 0 && o - ct[s - 1][1] >= 0 && dp[z - ct[s - 1][0]][o - ct[s - 1][1]] >= 0) {
                        dp[z][o] = max(dp[z][o], dp[z - ct[s - 1][0]][o - ct[s - 1][1]] + 1);
                        ans = max(ans, dp[z][o]);
                    }
                }
            }
        }
        return ans;
    }
};