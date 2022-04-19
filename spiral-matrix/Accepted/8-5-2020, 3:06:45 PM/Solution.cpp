// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return vector<int>(); 
        }
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        int M = matrix.size(); 
        int N = matrix[0].size(); 
        
        vector<vector<bool> > visited(M, vector<bool>(N, false)); 
        
        
        array<int, 2> pos = {0, 0}; 
        int x = 0;
        vector<int> ans; ans.reserve(M * N); 
        for (int i = 0; i < M * N; ++i) {
            
            array<int, 2> npos {pos[0] + dirs[x], pos[1] + dirs[x + 1]}; 
            if (npos[0] >= M || npos[0] < 0 || npos[1] >= N || npos[1] < 0 || visited[npos[0]][npos[1]]) {
                
                x += 1; 
                x = x % 4; 
            } 
                ans.push_back(matrix[pos[0]][pos[1]]); 
            
            visited[pos[0]][pos[1]] = true; 
            pos[0] += dirs[x]; 
            pos[1] += dirs[x + 1]; 
            
        }
        return ans; 
        
    }
};