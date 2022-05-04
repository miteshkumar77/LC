class Solution {
public:
    
    array<int, 5> dirs{0, 1, 0, -1, 0};
    
    bool possible(vector<vector<int>>& grid, vector<vector<int>>& fdist, int wait) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<array<int, 3>> q;
        q.push({0, 0, wait});
        while(!q.empty()) {
            auto [i, j, d] = q.front(); q.pop();
            if (i == n-1 && j == m-1 && d <= fdist[i][j]) return true;
            if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 2 && fdist[i][j] > d && !visited[i][j]) {
                visited[i][j] = true;
                for (int x = 0; x < 4; ++x)
                    q.push({i + dirs[x], j + dirs[x+1], d+1});
            }
        }
        return false;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        queue<array<int, 3>> q;
        vector<vector<int>> fdist(n, vector<int>(m, (int)1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j, 0});
                }
            }
        }
        
        while(!q.empty()) {
            auto [i, j, d] = q.front(); q.pop();
            if (i < n && i >= 0 && j < m && j >= 0 && d < fdist[i][j] && grid[i][j] != 2) {
                fdist[i][j] = d;
                for (int x = 0; x < 4; ++x) {
                    q.push({i + dirs[x], j + dirs[x+1], d+1});
                }
            }
        }
        
        int l = 0;
        int r = n * m;
        int mid;
        int ans = -1;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (possible(grid, fdist, mid)) {
                ans = mid; l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ((ans == (n * m)) ? 1e9 : ans);
    }
};