// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:

    array<int, 5> dirs{0, 1, 0, -1, 0};
    bool possible(vector<vector<int>>& grid, vector<vector<bool>>& visited, const int testMax, int currMax, int prevVal, int i, int j) {
      int n = grid.size();
      int m = grid[0].size();
      if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) return false;
      currMax = max(currMax, abs(grid[i][j] - prevVal));
      if (currMax > testMax) {
        return false;
      }
      if (i == n - 1 && j == m - 1) return true;
      visited[i][j] = true;
      for (int x = 0; x < 4; ++x) {
        if (possible(grid, visited, testMax, currMax, grid[i][j], i + dirs[x], j + dirs[x+1])) {
          return true;
        }
      }
      return false;
    }


    int minimumEffortPath(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<bool>> visited(n, vector<bool>(n, false));
      // cout << possible(grid, visited, 2, 0, grid[0][0], 0, 0);

      int l = 0; int r = INT_MAX; int ans = r; int mid;
      while(l <= r) {
        for (auto& v : visited) fill(v.begin(), v.end(), false);
        mid = l + (r - l)/2;
        // cout << mid << endl;
        if (possible(grid, visited, mid, 0, grid[0][0], 0, 0)) {
          ans = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      return ans;
    }
};