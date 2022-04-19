// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:
    const array<int, 5> dirs{0, 1, 0, -1, 0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> ks(m, vector<int>(n, -1));
        queue<array<int, 4>> q;
        q.push({0, 0, k, 0});
        while(!q.empty()) {
            auto t = q.front(); q.pop();
            if (t[0] < 0 || t[0] >= m || t[1] < 0 || t[1] >= n) continue;
            t[2] -= grid[t[0]][t[1]];
            if (ks[t[0]][t[1]] >= t[2]) continue;
            if (t[0] == m - 1 && t[1] == n - 1) return t[3];
            
            ks[t[0]][t[1]] = t[2];
            for (int i = 0; i < 4; ++i) q.push({t[0] + dirs[i], t[1] + dirs[i + 1], t[2], t[3] + 1});
        }
        return -1;
    }
};