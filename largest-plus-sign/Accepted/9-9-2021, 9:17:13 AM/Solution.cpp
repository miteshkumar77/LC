// https://leetcode.com/problems/largest-plus-sign

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& m) {
        vector<vector<int>> mines(n, vector<int>(n, 1));
        for (auto mine : m) {
            mines[mine[0]][mine[1]] = 0;
        }
        vector<vector<array<int, 4>>> dp(n+2, vector<array<int, 4>>(n+2, {0,0,0,0}));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (mines[i-1][j-1]) {
                    dp[i][j][0] = dp[i-1][j][0] + 1;
                    dp[i][j][1] = dp[i][j-1][1] + 1;
                }
            }
        }
        for (int i = n; i >= 1; --i) {
            for (int j = n; j >= 1; --j) {
                if (mines[i-1][j-1]) {
                    dp[i][j][2] = dp[i+1][j][2] + 1;
                    dp[i][j][3] = dp[i][j+1][3] + 1;
                }
            }
        }
        
        /*for (int x = 0; x < 4; ++x) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    cout << dp[i][j][x] << ' ';
                }
                cout << endl;
            }
            cout << endl << endl;
        }*/
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!mines[i-1][j-1]) continue;
                ans = max(ans, min(dp[i-1][j][0], min(dp[i][j-1][1], min(dp[i+1][j][2], dp[i][j+1][3]))) + 1);
            }
        }
        return ans;
    }
};