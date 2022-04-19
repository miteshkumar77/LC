// https://leetcode.com/problems/shortest-distance-to-target-color

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<array<int,3>> left(n, {(int)1e9, (int)1e9, (int)1e9});
        vector<array<int,3>> right(n, {(int)1e9, (int)1e9, (int)1e9});
        for (int i = 0; i < n; ++i) {
            left[i][colors[i]-1] = 0;
            right[i][colors[i]-1] = 0;
        } 
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                left[i][j] = min(left[i][j], left[i-1][j]+1);
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < 3; ++j) {
                right[i][j] = min(right[i][j], right[i+1][j]+1);
            }
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = min(left[queries[i][0]][queries[i][1]-1],
                        right[queries[i][0]][queries[i][1]-1]);
        }
        return ans;
    }
};