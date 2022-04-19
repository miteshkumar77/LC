// https://leetcode.com/problems/numbers-with-same-consecutive-differences

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            return vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
        }
        
        vector<vector<int>> dp(N, vector<int>()); 
        dp[0] = vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}; 
        
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < dp[i - 1].size(); ++j) {
                if (dp[i - 1][j] % 10 + K <= 9) {
                    dp[i].push_back(dp[i - 1][j] * 10 + dp[i - 1][j] % 10 + K); 
                }
                
                if (dp[i - 1][j] % 10 - K >= 0) {
                    dp[i].push_back(dp[i - 1][j] * 10 + dp[i - 1][j] % 10 - K); 
                }
            }
        }
        return dp.back(); 
        
    }
};