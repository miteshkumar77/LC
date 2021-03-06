// https://leetcode.com/problems/number-of-paths-with-max-score

typedef vector<int> pii; 

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<pii> > dp(board.size(), vector<pii>(board[0].size(), pii{0,0}));
        dp.back().back() = pii{0,1}; 
        int MOD = 1000000007; 
        int r = board.size(); 
        int c = board[0].size(); 
        array<int, 4> dirs{0, 1, 1, 0};
        for (int i = board.size() - 1; i >= 0; --i) {
            for (int j = board[0].size() - 1; j >= 0; --j) {
                if (board[i][j] != 'X') {
                    for (int x = 1; x < 4; ++x) {
                        int n_i = i + dirs[x]; 
                        int n_j = j + dirs[x - 1]; 
                        if (n_i < r && n_j < c && board[n_i][n_j] != 'X' && dp[n_i][n_j][1] != 0) {
                            if (dp[n_i][n_j][0] > dp[i][j][0]) {
                                dp[i][j][0] = dp[n_i][n_j][0];
                                dp[i][j][1] = dp[n_i][n_j][1]; 
                            } else if (dp[n_i][n_j][0] == dp[i][j][0]) {
                                dp[i][j][1] += dp[n_i][n_j][1]; dp[i][j][1] %= MOD;  
                            }
                        }
                        
                        
                    }
                    if (dp[i][j][1] != 0 && isdigit(board[i][j])) {
                        dp[i][j][0] += (int)(board[i][j] - '0'); 
                        // cout << (int)(board[i][j] - '0') << endl; 
                }

                }
            }
        }
        
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < r; ++j) {
                cout << dp[i][j][0] << ' '; 
            }cout << endl; 
        }
        return dp[0][0]; 
        
        
    }
};