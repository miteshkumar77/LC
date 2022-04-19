// https://leetcode.com/problems/game-of-life

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 2 0 -> 1
        // 3 1 -> 0
        int m = board.size(); 
        int n = board[0].size(); 
        array<int, 9> dirs{0, 1, -1, -1, 1, 1, 0, -1, 0};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int neighbors = 0;
                for (int x = 0; x < 8; ++x) {
                    
                    int newi = i + dirs[x]; 
                    int newj = j + dirs[x + 1]; 
                    if (newi < m && newi >= 0 && newj < n && newj >= 0) {
                        neighbors += board[newi][newj] % 2;
                    }
                }
                if (neighbors < 2 && board[i][j] == 1) {
                    board[i][j] = 3; 
                } else if (neighbors == 2 || neighbors == 3 && board[i][j] == 1) {
                    
                } else if (neighbors > 3 && board[i][j] == 1) {
                    board[i][j] = 3;
                } else if (neighbors == 3 && board[i][j] == 0) {
                    board[i][j] = 2; 
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 1; 
                } else if (board[i][j] == 3) {
                    board[i][j] = 0; 
                }
            }
        }
    }
};