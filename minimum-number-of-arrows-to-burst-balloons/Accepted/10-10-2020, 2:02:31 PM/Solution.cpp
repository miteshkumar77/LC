// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // [1,2],[2,3],[3,4],[4,5]
        
        if (points.size() == 0) {
            return 0;
        }
        
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1];
        });
        
        int latest = points[0][1];
        int ans = 1;
        
        for (int i = 1; i < points.size(); ++i) {
            if (latest < points[i][0]) {
                ++ans;
                latest = points[i][1];
            }
        }
        return ans;
    }
};