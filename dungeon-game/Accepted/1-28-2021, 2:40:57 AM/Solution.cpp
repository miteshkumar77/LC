// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                
                int prevstate;
                if (j == n - 1 && i == m - 1) {
                    dp[i][j] = dungeon[i][j] <= 0 ?-1 * dungeon[i][j] + 1:-1 * dungeon[i][j]; 
                    continue;
                }
                
                if (j == n - 1) {
                    prevstate = dp[i + 1][j];
                } else if (i == m - 1) {
                    prevstate = dp[i][j + 1];
                } else {
                    prevstate = min(dp[i + 1][j], dp[i][j + 1]);
                }
                if (dungeon[i][j] < 0) {
                    dp[i][j] = -1 * dungeon[i][j] + max(1, prevstate); 
                } else {
                    dp[i][j] = prevstate - dungeon[i][j];
                }
            }
        }
        // for (auto v : dp) {
        //     for (int i : v) cout << i << ' ';
        //     cout << endl;
        // }
        return max(1, dp[0][0]);
    }
};