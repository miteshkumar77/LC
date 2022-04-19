// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool solved = false;
        int n = board.size();
        const int lim = 9 * 9;
        
        vector<unordered_set<char>> row_occupied(n, unordered_set<char>());
        vector<unordered_set<char>> col_occupied(n, unordered_set<char>());
        vector<vector<unordered_set<char>>> square_occupied(3, vector<unordered_set<char>>(3, unordered_set<char>()));
        
        function<void(int,int,char)> insert = [&](int i, int j, char c) -> void {
            row_occupied[i].insert(c);
            col_occupied[j].insert(c);
            square_occupied[i/3][j/3].insert(c);
        };
        
         function<void(int,int,char)> erase = [&](int i, int j, char c) -> void {
            row_occupied[i].erase(c);
            col_occupied[j].erase(c);
            square_occupied[i/3][j/3].erase(c);
        };
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    insert(i, j, board[i][j]);
                }
            }
        }
        
        
        function<bool(int,int,char)> check = [&](int i, int j, char c) -> bool {
            return row_occupied[i].find(c) == row_occupied[i].end() &&
                col_occupied[j].find(c) == col_occupied[j].end() &&
                square_occupied[i/3][j/3].find(c) == square_occupied[i/3][j/3].end();
        };
        
        // cout << check(0, 2, '5') << endl;
        
        function<void(int)> bt = [&](int square) -> void {
            if (solved) {
                return;
            }
            if (square == lim) {
                
                solved = true;
                return;
            }
            int row = square / n;
            int col = square % n;

            if (board[row][col] != '.') {
                bt(square + 1);
                return;
            }
            for (int i = 1; i <= n; ++i) {
                if (check(row, col, (char)(i + '0'))) {
                    board[row][col] = (char)(i + '0');
                    insert(row, col, (char)(i + '0'));
                    bt(square + 1);
                    if (solved) {
                        return;
                    }
                    board[row][col] = '.';
                    erase(row, col, (char)(i + '0'));
                }
            }
            
        };
        
        bt(0);
    }
};