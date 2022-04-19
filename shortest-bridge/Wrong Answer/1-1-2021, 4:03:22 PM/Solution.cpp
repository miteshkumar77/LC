// https://leetcode.com/problems/shortest-bridge

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        int shortest1 = INT_MAX - 100;
        int shortest2 = INT_MAX - 100;
        
        vector<vector<int>> dp1(m, vector<int> (n, INT_MAX - 100));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != 0) {
                    dp1[i][j] = min(dp1[i - 1][j] + 1, dp1[i][j]); 
                }
                if (j != 0) {
                    dp1[i][j] = min(dp1[i][j - 1] + 1, dp1[i][j]);
                }
                
                if (A[i][j] == 1) {
                    shortest1 = min(shortest1, dp1[i][j] - 1);
                    dp1[i][j] = 0;
                }
            }
        }
        
        dp1 = vector<vector<int>>(m, vector<int>(n, INT_MAX - 100));
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (i != m - 1) {
                    dp1[i][j] = min(dp1[i + 1][j] + 1, dp1[i][j]);
                }
                if (j != 0) {
                    dp1[i][j] = min(dp1[i][j - 1] + 1, dp1[i][j]);
                }
                
                if (A[i][j] == 1) {
                    shortest2 = min(shortest2, dp1[i][j] - 1);
                    dp1[i][j] = 0;
                }
            }
        }
        
        return min(shortest1, shortest2);
        
    }
};