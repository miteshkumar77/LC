// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1];
        });
        
        int ans = 1;
        int min_interval = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > min_interval) {
                ++ans;
                min_interval = points[i][1];
            }
        }
        return ans;
    }
};