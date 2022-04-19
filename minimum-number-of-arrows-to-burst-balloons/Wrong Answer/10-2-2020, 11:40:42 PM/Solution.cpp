// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0];
        });
        
        int ans = 0;
        int min_interval = -1;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] > min_interval) {
                ++ans;
                min_interval = points[i][1];
            }
        }
        return ans;
    }
};