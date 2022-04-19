// https://leetcode.com/problems/number-of-corner-rectangles

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<unordered_set<int>> rows(m, unordered_set<int>()); 
        vector<unordered_set<int>> cols(n, unordered_set<int>()); 
        
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