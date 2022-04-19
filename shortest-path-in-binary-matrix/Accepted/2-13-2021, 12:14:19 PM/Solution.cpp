// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        array<int, 8> dx{0, 0, 1, 1, 1, -1, -1, -1};
        array<int, 8> dy{-1, 1, -1, 0, 1, -1, 0, 1}; 
        queue<array<int, 3>> bfsq;
        bfsq.push({0, 0, 1});
        
        while(!bfsq.empty()) {
            auto a = bfsq.front();
            bfsq.pop();
            if (a[0] >= n || a[0] < 0 || a[1] >= m || a[1] < 0 || grid[a[0]][a[1]] != 0) {
                continue;
            }
            if (a[0] == n - 1 && a[1] == m - 1) return a[2];
            grid[a[0]][a[1]] = 1; 
            for (int i = 0; i < 8; ++i) {
                bfsq.push({a[0] + dx[i], a[1] + dy[i], a[2] + 1});
            }
        }
        return -1; 
    }
};