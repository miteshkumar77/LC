// https://leetcode.com/problems/number-of-boomerangs

class Solution {
public:
    
    int dist(const vector<int>& p1, const vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]); 
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (int anchor = 0; anchor < points.size(); ++anchor) {
            unordered_map<int, int> count;
            for (int point = 0; point < points.size(); ++point) {
                if (point == anchor) continue;
                ++count[dist(points[anchor], points[point])]; 
            }
            for (auto p : count) {
                ans += p.second * (p.second - 1); 
            }
        }
        
        return ans;
    }
    
};