// https://leetcode.com/problems/number-of-corner-rectangles

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<set<int>> rows(m, set<int>()); 
        vector<set<int>> cols(n, set<int>()); 
        
        /*
         iv,jv       iv,j
           
        
          i,jv        i,j
        */
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (grid[i][j]) {
                    
                    for (auto iv : cols[j]) {
                        for (auto jv : rows[iv]) {
                            if (rows[i].count(jv)) {
                                ++ans;
                            }
                        }
                    }
                    
                    rows[i].insert(j);
                    cols[j].insert(i); 
                }
            }
        }
        return ans;
    }
};