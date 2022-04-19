// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    typedef array<int, 2> pii; 
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size(); int N = grid[0].size(); 
        vector<vector<int> > dist(M, vector<int>(N, INT_MAX)); 
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        function<void(int,int)>bfs = [&](int row, int col) -> void {
            queue<pii> q; 
            dist[row][col] = 0; 
            q.push(pii{row, col}); 
            
            while(!q.empty()) {
                pii top = q.front(); q.pop(); 
                for (int x = 0; x < 4; ++x) {
                    int ni = dirs[x] + top[0]; 
                    int nj = dirs[x + 1] + top[1]; 
                    if (ni >= 0 && nj >= 0 && ni < M && nj < N && grid[ni][nj] == 1 && dist[top[0]][top[1]] + 1 < dist[ni][nj]) {
                        dist[ni][nj] = dist[top[0]][top[1]] + 1; 
                        q.push(pii{ni, nj}); 
                    }
                }
            }
            
        }; 
        
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 2) {
                    bfs(i, j); 
                }
            }
        }
        
        int ans = 0; 
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dist[i][j]);
                }
            } 
        }
        if (ans == INT_MAX) {
            return -1; 
        }
        return ans; 
    }
    
    
    
};