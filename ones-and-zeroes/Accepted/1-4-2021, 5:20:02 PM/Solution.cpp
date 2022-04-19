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
        
        // for (auto v : ct) {
        //     cout << v[0] << ' ' << v[1] << endl;
        // }
        
        /**
        
            dp[i][j][k] = max size subset of strings 1 to i that can 
            sum to j 0s and k 1s. 
        */
        
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        for (int i = 0; i <= N; ++i) {
            dp[i][0][0] = 0;
        }
        
        int ans = 0;
        
        for (int str = 1; str <= N; ++str) {
            for (int z = 0; z <= m; ++z) {
                for (int o = 0; o <= n; ++o) {
                    
                    if (z - ct[str - 1][0] >= 0 && o - ct[str - 1][1] >= 0 && dp[str - 1][z - ct[str - 1][0]][o - ct[str - 1][1]] >= 0) {
                        dp[str][z][o] = dp[str - 1][z - ct[str - 1][0]][o - ct[str - 1][1]] + 1; 
                    }
                    
                    dp[str][z][o] = max(dp[str][z][o], dp[str - 1][z][o]);
                    
                    ans = max(ans, dp[str][z][o]);
                    
                }
            }
        }
        
        return ans;
    }
};