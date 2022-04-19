// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int>>& d) {
        
        int M = d.size(); int N = d[0].size(); 
        vector<vector<int> > dp(M, vector<int>(N, 0));
                
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (j == N - 1 && i == M - 1) {
                    dp[i][j] = -d[i][j]; 

                } else if (j == N - 1) {
                    dp[i][j] = dp[i + 1][j] - d[i][j]; 

                } else if (i == M - 1) {
                    dp[i][j] = dp[i][j + 1] - d[i][j]; 
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - d[i][j]; 
                }
                if (dp[i][j] <= 0) {
                    dp[i][j] = 1; 
                }

            }
        }
        
        
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                cout << dp[i][j] << ' '; 
            }cout << endl; 
        }
        return dp[0][0]; 
    }

};