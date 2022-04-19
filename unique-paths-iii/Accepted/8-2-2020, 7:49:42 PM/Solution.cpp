// https://leetcode.com/problems/unique-paths-iii

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int si; int sj; int ei; int ej; 
        int M = grid.size(); int N = grid[0].size(); 
        int maxV = M * N; 
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    si = i; sj = j; 
                }
                if (grid[i][j] == -1) {
                    --maxV; 
                }
                if (grid[i][j] == 2) {
                    ei = i; ej = j; 
                }
            }
        }
        array<int, 5> dirs {0, 1, 0, -1, 0}; 
        int visited = 0; 
        function<int(int,int)> bt = [&] (int i, int j) {
            if (i >= 0 && j >= 0 && i < M && j < N && grid[i][j] != -1) {
                
                
                if (grid[i][j] == 2) {
                    if (visited == maxV - 1) {
                        return 1; 
                    } else {
                        return 0; 
                    }
                }
                
                
                int tmp = grid[i][j]; 
                grid[i][j] = -1; 
                ++visited; 
                int ans = 0; 
                for (int x = 0; x < 4; ++x) {
                    ans += bt(i + dirs[x], j + dirs[x + 1]); 
                }
                
                grid[i][j] = tmp; 
                --visited; 
                return ans; 
                
            } else {
                return 0; 
            }
        };
        
        return bt(si, sj); 
    }
};