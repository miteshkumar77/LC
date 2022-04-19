// https://leetcode.com/problems/word-search

class Solution {
public:
    const array<int, 9> dirs{1, 1, 0, -1, -1, 0, 1, -1, 1};
    int m;
    int n; 
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); 
        n = board[0].size(); 
        vector<vector<bool> > visited(m, vector<bool>(n, false)); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i][j] = true; 
                if (board[i][j] == word[0] && backtrack(board, i, j, visited, word, 1)) {
                    return true; 
                }
                visited[i][j] = false;
            }
        }
        return false; 
    }
    
    
    bool backtrack(vector<vector<char>>& board, int i, int j, 
                   vector<vector<bool> >& visited, string& word, int c) {
        if (c == word.length()) {
            return true; 
        }
        
        
        for (int x = 0; x < 8; ++x) {
            
            int newi = i + dirs[x];
            int newj = j + dirs[x + 1]; 
            
            // cout << x << ": " << newi << ' ' << newj << endl; 

            if (newi >= 0 && newi < m && newj >= 0 && newj < n && 
                board[newi][newj] == word[c] && !visited[newi][newj]) {
                // cout << board[newi][newj] << endl; 
                visited[newi][newj] = true;
                if (backtrack(board, newi, newj, visited, word, c + 1)) {
                    return true; 
                }
                visited[newi][newj] = false; 
            }
        }
        return false; 
        
    }
};