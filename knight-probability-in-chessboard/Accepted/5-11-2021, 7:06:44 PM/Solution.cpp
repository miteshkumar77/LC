// https://leetcode.com/problems/knight-probability-in-chessboard

class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        array<int, 8> dx{-1,1,2,2,1,-1,-2,-2};
        array<int, 8> dy{2,2,1,-1,-2,-2,-1,1};
        
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k, -1)));
        function<double(int,int,int)> sol = [&](int i, int j, int k) -> double {
            if (i < 0 || i >= n || j < 0 || j >= n) {
                return 0;
            }
            if (k == 0) {
                return 1;
            }
            if (dp[i][j][k-1] >= 0) {
                return dp[i][j][k-1];    
            }
            double ans = 0;
            for (int x = 0; x < 8; ++x) {
                ans += (1.0/8.0) * sol(i + dx[x], j + dy[x], k-1);
            }
            dp[i][j][k-1] = ans;
            return dp[i][j][k-1];
        };
        return sol(r, c, k);
    }
};