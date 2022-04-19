// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    
    array<int, 5> dirs {0, 1, 0, -1, 0}; 
    void solve(vector<vector<char>>& board) {
        vector<vector<bool> > visited (board.size(), vector<bool>(board[0].size(), false)); 
        // bfs_fill(board, 1, 1); 
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (!visited[i][j] && board[i][j] == 'O' && dfs_check(board, i, j, visited)) {
                   
                    bfs_fill(board, i, j); 
                    return; 
                }
            }
        }
    }
    
    bool dfs_check(vector<vector<char>>& board, int i, int j, vector<vector<bool> >& visited) {
        visited[i][j] = true; 
        if (board[i][j] == 'X') {
            return true; 
        }
        if (i == 0 || i + 1 == board.size() || j == 0 || j + 1 == board[i].size()) {
            return false; 
        }
        
        for (int x = 1; x < 5; ++x) {
            int n_i = dirs[x - 1] + i; 
            int n_j = dirs[x] + j; 
            if (n_i >= 0 && n_i < board.size() && n_j >= 0 && n_j < board[n_i].size() && !visited[n_i][n_j]) {
                if (!dfs_check(board, n_i, n_j, visited)) {
                    return false; 
                }
            }
        }
        return true; 
    }
    
    
    void bfs_fill(vector<vector<char> >& board, int i, int j) {
        queue<array<int, 2> > q; q.push(array<int, 2>{i, j}); 
        while(!q.empty()) {
            
            array<int, 2> top = q.front(); q.pop();  
            // cout << top[0] << ' ' << top[1] << endl; 
            board[top[0]][top[1]] = 'X'; 
            for (int x = 1; x < 5; ++x) {
                // cout << dirs[x - 1] << ' ' << dirs[x] << endl; 
                int n_i = dirs[x - 1] + top[0]; 
                int n_j = dirs[x] + top[1]; 
                
                if (board[n_i][n_j] != 'X') {
                    
                    q.push(array<int, 2>{n_i, n_j}); 
                    
                }
                    
            }
        }
    }
};