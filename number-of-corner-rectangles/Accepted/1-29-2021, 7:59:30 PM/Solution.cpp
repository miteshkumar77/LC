// https://leetcode.com/problems/number-of-corner-rectangles

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0)); 
        
        /*
         iv,jv       iv,j
           
        
          i,jv        i,j
        */
        
        unordered_set<int> seen;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            seen.clear(); 
            for (int j = 0; j < n; ++j) {
                
                if (grid[i][j]) {
                    
                    for (int j0 : seen) {
                        ans += dp[j][j0];
                        ++dp[j][j0];
                    }
                    seen.insert(j); 
                }
            }
    
        }
        
        return ans;
    }
};