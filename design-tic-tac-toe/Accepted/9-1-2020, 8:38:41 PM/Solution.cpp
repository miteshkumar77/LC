// https://leetcode.com/problems/design-tic-tac-toe

class TicTacToe {
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rowct = vector<int>(n, 0); 
        colct = vector<int>(n, 0); 
        rowchar = vector<char>(n, ' ');
        colchar = vector<char>(n, ' '); 
        d1 = 0; 
        d2 = 0; 
        cd1 = ' ';
        cd2 = ' '; 
        N = n; 
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int mark = (player == 1)?'X':'O'; 
        if (rowchar[row] == ' ') {
            rowchar[row] = mark; 
        }
        if (rowchar[row] == mark) {
            ++rowct[row]; 
            if (rowct[row] == N) {
                return player; 
            }
        } else {
            rowchar[row] = 'D'; 
        }
        
        if (colchar[col] == ' ') {
            colchar[col] = mark; 
        }
        if (colchar[col] == mark) {
            ++colct[col]; 
            if (colct[col] == N) {
                return player; 
            }
        } else {
            colchar[col] = 'D'; 
        }
        
        if (row == col) {
            if (cd1 == ' ') {
                cd1 = mark; 
            }
            if (cd1 == mark) {
                ++d1; 
                if (d1 == N) {
                    return player; 
                }
            } else {
                cd1 = 'D'; 
            }
        }
        
        if (row == N - col - 1) {
            if (cd2 == ' ') {
                cd2 = mark; 
            }   
            if (cd2 == mark) {
                ++d2; 
                if (d2 == N) {
                    return player; 
                }
            } else {
                cd2 = 'D'; 
            }
        }
        return 0; 
    }
    
    
    
private: 
    int N; 
    vector<int> rowct; 
    vector<char> rowchar; 
    vector<int> colct; 
    vector<char> colchar; 
    int d1; 
    int d2;
    char cd1; 
    char cd2; 
    
    
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */