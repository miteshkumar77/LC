// https://leetcode.com/problems/swim-in-rising-water

#define P(name) cout << #name << "(" << (name) << ") "
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        auto cmp = [](array<int,3> const& a, array<int,3> const& b) -> bool {
            return a[2] > b[2];
        };
        array<int, 5> dirs{0, 1, 0, -1, 0};
        priority_queue<array<int,3>, vector<array<int,3>>, decltype(cmp)> q(cmp);
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        q.push({0,0,grid[0][0]});
        while(!q.empty()) {
            auto t = q.top(); q.pop();
            if (t[0] == N-1 && t[1] == t[0]) return t[2];
            if (visited[t[0]][t[1]]) continue;
            visited[t[0]][t[1]] = 1;
            for (int i = 0; i < 4; ++i) {
                int nx = t[0] + dirs[i]; int ny = t[1] + dirs[i+1];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    //P(t[0]);P(t[1]);P(t[2]);P(nx); P(ny); cout << endl;
                    q.push({nx, ny, t[2] + max(0, grid[nx][ny]-grid[t[0]][t[1]])});
                }
            }
        }
        return -1;
    }
};