class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        array<int, 5> dirs{0, 1, 0, -1, 0};
        while(!pq.empty()) {
            auto [d, i, j] = pq.top(); pq.pop();
            if (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j]) {
                visited[i][j] = true;
                d += grid[i][j];
                if (i == n-1 && j == m-1)
                    return d;
                for (int x = 0; x < 4; ++x) {
                    int ni = i + dirs[x]; int nj = j + dirs[x+1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]) {
                        pq.push({d, i + dirs[x], j + dirs[x+1]});
                    }
                }
            }
        }
        return -1;
    }
};