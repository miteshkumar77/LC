// https://leetcode.com/problems/the-maze-ii

class Solution {
public:
    typedef pair<int,array<int,2>> pqElem;
    array<int, 5> dirs{0, 1, 0, -1, 0};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pqElem, vector<pqElem>, greater<pqElem>> minq;
        minq.push({0, {start[0], start[1]}});
        while(!minq.empty()) {
            auto [dist, pos] = minq.top();
            minq.pop();
            if (visited[pos[0]][pos[1]]) continue;
            visited[pos[0]][pos[1]] = true;
            if (pos[0] == destination[0] && pos[1] == destination[1]) return dist;
            for (int i = 0; i < 4; ++i) {
                int x = pos[0];
                int y = pos[1];   
                while(x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0) {
                    x += dirs[i];
                    y += dirs[i+1];
                }
                x -= dirs[i];
                y -= dirs[i+1];
                minq.push({dist + abs(x - pos[0]) + abs(y - pos[1]), {x, y}});
            }
        }
        return -1;
    }
};