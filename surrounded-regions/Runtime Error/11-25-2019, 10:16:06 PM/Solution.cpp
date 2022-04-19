// https://leetcode.com/problems/surrounded-regions

#include <utility>
#include <list>

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        
        if (board.size() < 3 || board[0].size() < 3) {
            return; 
        }
        vector<vector<char> > board_copy = board; 
        
        list<pair<int, int> > coords; 
        for (int i = 1; i < board.size() - 1; i++) {
            
            for (int j = 1; j < board.size() - 1; j++) {
                
                if (sub_solve(board_copy, i, j, coords)) {
                    for (list<pair<int, int>>::iterator iter = coords.begin(); iter !=                                  coords.end(); iter++) {
                        
                        board[iter -> first][iter -> second] = 'X'; 
                    }
                }
            }
        }
    }
    
    bool sub_solve(vector<vector<char> >& board_copy, int i, int j, list<pair<int, int> >& coords) {
        if (board_copy[i][j] == 'X') {
            return false; 
        }
        
        board_copy[i][j] = 'X'; 
        
        
        if (i == 0 || j == 0 || i == board_copy.size() || j == board_copy[i].size()) {
            return false; 
        }
        
        coords.push_back(make_pair(i, j)); 
        
        bool u = true; 
        bool d = true; 
        bool l = true; 
        bool r = true; 
        
        if (board_copy[i - 1][j] == 'O') {
            u = sub_solve(board_copy, i - 1, j, coords);
        }
        
        if (board_copy[i + 1][j] == 'O') {
            d = sub_solve(board_copy, i + 1, j, coords);
        }
        
        if (board_copy[i][j - 1] == 'O') {
            l = sub_solve(board_copy, i, j - 1, coords);
        }
        
        if (board_copy[i][j + 1] == 'O') {
            r = sub_solve(board_copy, i, j + 1, coords);
        }
        
        return u && d && l && r; 
        
        
    }
    
    
    
    
};