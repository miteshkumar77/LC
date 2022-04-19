// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<array<int, 9>> r(9, array<int, 9>{});
        vector<array<int, 9>> c(9, array<int, 9>{});
        vector<vector<array<int, 9>>> s(3, vector<array<int, 9>>(3, array<int, 9>{}));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int piece = board[i][j] - '1';
                    if (r[i][piece]) return false;
                    r[i][piece] = true;
                    if (c[j][piece]) return false;
                    c[j][piece] = true;
                    if (s[i/3][j/3][piece]) return false;
                    s[i/3][j/3][piece] = true;
                }
            }
        }
        return true;
    }
};