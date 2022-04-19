// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if (points.size() == 0) {
            return 0; 
        }
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] < b[1]; 
        });
        
        
        int min_end = points[0][1]; 
        int ans = 0; 
        for (int i = 1; i < points.size(); ++i) {
            vector<int>& p = points[i]; 
            if (p[0] > min_end) {
                ++ans; 
                min_end = p[1]; 
            }
        }
        
        ans += 1; 
        return ans; 
    }
};