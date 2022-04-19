// https://leetcode.com/problems/the-maze

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false)); 
        int M = visited.size(); 
        int N = visited[0].size(); 
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        
        
        function<bool(int,int)> checkPos = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < M && j < N && maze[i][j] == 0; 
        };
        
        function<bool(int,int)> dfs = [&](int i, int j) -> bool {
            
            if (i == destination[0] && j == destination[1]) {
                return true; 
            }
            
            if (visited[i][j]) {
                return false; 
            }
            
            visited[i][j] = true; 
            for (int x = 0; x < 4; ++x) {
                int ni = i; 
                int nj = j; 
                while(checkPos(ni + dirs[x], nj + dirs[x + 1])) {
                    ni += dirs[x]; 
                    nj += dirs[x + 1]; 
                }
                
                if (dfs(ni, nj)) {
                    return true; 
                }
            }
            return false; 
        };
        
        return dfs(start[0], start[1]);
    }
};