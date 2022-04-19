// https://leetcode.com/problems/line-reflection

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int,int>> levels;
        for (int i = 0; i < points.size(); ++i) {
            ++levels[points[i][1]][points[i][0]];
        }
        
        int minx = INT_MAX;
        int maxx = INT_MIN;
        for (auto [pidx, ct] : levels.begin() -> second) {
            minx = min(minx, pidx);
            maxx = max(maxx, pidx); 
        }
        
        int y = (maxx + minx)/2;
        int half = 0;
        if ((maxx - minx) % 2 != 0) {
            half = 1;
        }
        
        // cout << minx << ' ' << maxx << endl;
        
        for (auto p : levels) {
            for (auto [x, ct] : p.second) {
                int reflected;
                if ((half && (double)x < (double)y + (1.0/2.0)) || (x < y)) {
                    reflected = x + (y - x) * 2 + half;
                } else {
                    reflected = x - (x - y) * 2 + half;
                }
                
                // cout << x << ' ' << p.first << ' ' << ct << ' ' << reflected << ' ' << (double)y + (1.0/2.0) * (double)(half) << endl;
                if (!p.second.count(reflected)) {
                    return false;
                }
            }
        }
        return true;
    }
};