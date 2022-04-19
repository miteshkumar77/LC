// https://leetcode.com/problems/making-a-large-island

class Solution {
public:
    array<int, 5> dirs{0, 1, 0, -1, 0};
    int bfs(int i, int j, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sz = 0;
        queue<array<int,2>> q;
        q.push({i,j});
        while(!q.empty()) {
            auto t = q.front(); q.pop();
            if (t[0] < 0 || t[0] >= n || t[1] < 0 || t[1] >= m || grid[t[0]][t[1]] != 1) {
                continue;
            }
            grid[t[0]][t[1]] = c;
            ++sz;
            for (int x = 0; x < 4; ++x) q.push({t[0] + dirs[x], t[1] + dirs[x+1]});
        }
        return sz;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 2;
        unordered_map<int,int> col;
        col[0] = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                col[c] = bfs(i, j, c, grid);
                ans = max(ans, col[c]);
                ++c;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> colors;
                    for (int x = 0; x < 4; ++x) {
                        int ni = i + dirs[x]; int nj = j + dirs[x+1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            colors.insert(grid[ni][nj]);
                        }
                    }
                    int tmpans = 1;
                    
                    for (int i : colors) {
                        tmpans += col[i];
                    }
                    ans = max(ans, tmpans);
                }
            }
        }
        return ans;
    }
};