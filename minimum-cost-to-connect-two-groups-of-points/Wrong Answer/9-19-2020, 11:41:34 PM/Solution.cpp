// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points

class Solution {
public:
    typedef pair<int,int> pii; 
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m = cost.size(); int n = cost[0].size(); 
        int ans = 0; 
        vector<pii> pts; 
        vector<int> dh(m, n); 
        vector<int> dv(n, m);
        for (int i = 0; i < cost.size(); ++i) {
            for (int j = 0; j < cost[i].size(); ++j) {
                pts.push_back(pii(i,j)); 
                ans += cost[i][j]; 
            }
        }
        
        sort(pts.begin(), pts.end(), [&](pii& a, pii&b) -> bool {
            return cost[a.first][a.second] >= cost[b.first][b.second];    
        });
        
        // int ans = pts.size(); 
        
        for (int i = 0; i < pts.size(); ++i) {
            pii p = pts[i]; 
            
            if (dh[p.first] > 1 && dv[p.second] > 1) {
                --dh[p.first]; --dv[p.second];
                ans -= cost[p.first][p.second]; 
            }
        }
        return ans; 
        
        
    }
};