// https://leetcode.com/problems/minimum-time-visiting-all-points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0; 
        for (int i = 0; i < points.size() - 1; ++i) {
            ans += mindist(points[i], points[i + 1]); 
        }
        return ans; 
    }
    
    
    int mindist(vector<int>& p1, vector<int>& p2) {
        
        int dx = abs(p1[0] - p2[0]); 
        int dy = abs(p1[1] - p2[1]); 
        return max(dx, dy); 
        
    }
};