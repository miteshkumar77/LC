// https://leetcode.com/problems/candy-crush

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        
        
        function<bool()> eliminate_candies = [&]() -> bool {
            
            vector<vector<int> > mark(board.size(), vector<int>(board.size(), false));
            
            for (int i = 0; i < board.size(); ++i) {
                int prev = -1;
                int num_prev = 0;
                
                for (int j = 0; j < board[i].size(); ++j) {
                    if (prev == -1) {
                        prev = j; 
                        num_prev = 1; 
                    } else if (board[i][prev] == board[i][j]) {
                        ++num_prev;
                    } else {

                        if (num_prev >= 3) {
                            for (int x = prev; x < j; ++x) {
                                mark[i][x] = true; 
                            }
                        }
                        prev = j; 
                        num_prev = 1; 
                    }
                }
                if (num_prev >= 3) {
                    for (int x = prev; x < board[i].size(); ++x) {
                        mark[i][x] = true; 
                    }
                }
            }
            
            for (int j = 0; j < board[0].size(); ++j) {
                int prev = -1;
                int num_prev = 0;
                for (int i = 0; i < board.size(); ++i) {
                    
                    if (prev == -1) {
                        prev = i; 
                        num_prev = 1; 
                    } else if (board[prev][j] == board[i][j]) {
                        ++num_prev;
                    } else {
                        if (num_prev >= 3) {
                            for (int x = prev; x < i; ++x) {
                                mark[x][j] = true; 
                            }
                        }
                        
                        prev = i; 
                        num_prev = 1; 
                    }
                }
                if (num_prev >= 3) {
                    for (int x = prev; x < board.size(); ++x) {
                        mark[x][j] = true; 
                    }
                }
                        
            }
            
            int marks = 0; 
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board.size(); ++j) {
                    if (mark[i][j] && board[i][j] != 0) {
                        
                        ++marks; 
                        board[i][j] = 0; 
                    }
                }
            }
            
            // cout << marks << endl; 
            return marks > 0; 
        };
        
        
        auto shift_col = [&](int col) -> void {
            list<int> mem;
            for (int i = board.size() - 1; i >= 0; --i) {
                if (board[i][col] != 0) {
                    mem.push_back(board[i][col]); 
                }
            }
            int j = board.size() - 1;
            for (int i : mem) {
                board[j][col] = i;
                --j;
            }
            
            for (int i = j; i >= 0; --i) {
                board[i][col] = 0; 
            }
            
        };
        
        
        while(true) {
            if (!eliminate_candies()) {
                return board; 
            }
            
            
            
            for (int i = 0; i < board[0].size(); ++i) {
                shift_col(i);
            }
        }
        
        
        
    }
    
    
    
};