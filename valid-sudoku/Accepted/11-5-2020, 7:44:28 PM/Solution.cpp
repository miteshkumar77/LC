// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = 9; 
        
        vector<unordered_set<char>> row_occupied(n, unordered_set<char>());
        vector<unordered_set<char>> col_occupied(n, unordered_set<char>());
        vector<vector<unordered_set<char>>> square_occupied(3, vector<unordered_set<char>>(3, unordered_set<char>()));
        
        function<void(int,int,char)> insert = [&](int i, int j, char c) -> void {
            row_occupied[i].insert(c);
            col_occupied[j].insert(c);
            square_occupied[i/3][j/3].insert(c);
        };
        
        function<bool(int,int,char)> check = [&](int i, int j, char c) -> bool {
            return row_occupied[i].find(c) == row_occupied[i].end() &&
                col_occupied[j].find(c) == col_occupied[j].end() &&
                square_occupied[i/3][j/3].find(c) == square_occupied[i/3][j/3].end();
        };
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                
                if (board[i][j] != '.') {
                    if (!check(i, j, board[i][j])) {
                        return false;
                    }
                    insert(i, j, board[i][j]);
                }
                
            }
        }
        
        return true;
    }
};