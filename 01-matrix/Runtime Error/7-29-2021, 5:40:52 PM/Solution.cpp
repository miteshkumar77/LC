// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); int n = mat[0].size();
        queue<array<int,3>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j]==0) {
                    q.push({i, j, 0});
                }
            }
        }
        array<int, 5> dirs{0, 1, 0, -1, 0};
        while(!q.empty()) {
            auto t = q.front(); q.pop();
            if (t[0] < 0 || t[0] >= n || t[1] < 0 || t[1] >= m) continue;
            if (visited[t[0]][t[1]]) continue;
            visited[t[0]][t[1]] = true;
            mat[t[0]][t[1]] = t[2];
            for (int d = 0; d < 4; ++d) {
                q.push({t[0] + dirs[d], t[1] + dirs[d+1], t[2] + 1});
            }
        }
        return mat;
    }
};