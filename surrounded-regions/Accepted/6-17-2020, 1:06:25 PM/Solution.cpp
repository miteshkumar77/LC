// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    
    array<int, 5> dirs {0, 1, 0, -1, 0}; 
    void solve(vector<vector<char>>& board) {
        
        if (board.size() == 0 || board[0].size() == 0) {
            return; 
        }
        vector<vector<bool> > visited (board.size(), vector<bool>(board[0].size(), false)); 
        
        
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O') {
                bfs_fill(board, i, 0, visited); 
            }
            
            if (board[i][board[i].size() - 1] == 'O') {
                bfs_fill(board, i, board[i].size() - 1, visited); 
            }
        }
        
        for (int j = 1; j < board[0].size() - 1; ++j) {
            if (board[0][j] == 'O') {
                bfs_fill(board, 0, j, visited); 
            }
            
            if (board[board.size() - 1][j] == 'O') {
                bfs_fill(board, board.size() - 1, j, visited); 
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X'; 
                } 
            }
        }
    }
    
    
    
    
    void bfs_fill(vector<vector<char> >& board, int i, int j, vector<vector<bool> >& visited) {
        if (visited[i][j]) {
            return; 
        }
        queue<array<int, 2> > q; q.push(array<int, 2>{i, j}); 
        visited[i][j] = true; 
        while(!q.empty()) {
            
            array<int, 2> top = q.front(); q.pop();  
            
            for (int x = 1; x < 5; ++x) {
                int n_i = dirs[x - 1] + top[0]; 
                int n_j = dirs[x] + top[1]; 
                
                if (n_i >= 0 && n_i < board.size() &&
                    n_j >= 0 && n_j < board[0].size() && board[n_i][n_j] == 'O' && !visited[n_i][n_j]) {
                    visited[n_i][n_j] = true; 
                    q.push(array<int, 2>{n_i, n_j}); 
                }
                    
            }
        }
    }
};