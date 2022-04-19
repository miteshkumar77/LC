// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        
        int n = points.size();
        int ans = 1;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] < b[0] || (a[0] == b[0] && a[1] <= b[1]); 
        });
        
        int latest = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > latest) {
                ++ans;
                latest = points[i][1];
            } else {
                latest = min(latest, points[i][1]);
            }
        }
        return ans;
    }
};