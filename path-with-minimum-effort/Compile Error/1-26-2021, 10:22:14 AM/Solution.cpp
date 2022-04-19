// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    array<int, 5> dirs{0, 1, 0, -1, 0};
    bool exists(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int limit, int i, int j, int prev_val, int max_seen) {
        if (i >= heights.size() || i < 0 || j >= heights[0].size() || j < 0 || visited[i][j]) {
            return false;
        }
        
        max_seen = max(max_seen, abs(heights[i][j] - prev_val)); 
        if (limit < max_seen) {
            return false;
        }
        
        if (i == heights.size() - 1 && j == heights[0].size() - 1) {
            return true;
        }
        visited[i][j] = true;
        for (int x = 0; x < 4; ++x) {
            if (exists(heights, visited, limit, i + dirs[x], j + dirs[x + 1], heights[i][j], max_seen)) {
                return true;
            }
        }
        
        return false;

    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0;
        int r = 0;
        
        for (auto& v : heights) {
            for (auto i : v) r = max(r, i); 
        }
        
        
        int mid;
        int ans = r;
        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false)); 
        while(l <= r) {
            for (int i = 0; i < heights.size(); ++i) {
                for (int j = 0; j < heights[0].size(); ++j) {
                    visited[i][j] = false;
                }
            }
            mid = l + (r - l)/2;
            if (exists(heights, visited, mid, 0, 0, heights[i][j], INT_MIN)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
        
    }
};