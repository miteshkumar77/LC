// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        
        
        
        function<bool(int,int,int,int)> bsearch = [&](int x0, int y0, int x1, int y1) -> bool {
            if (x0 > x1 || y0 > y1) {
                return false; 
            }
            
            int midy = y0 + (y1 - y0)/2; 
            int midx = x0; 
            while(midx <= x1 && matrix[midy][midx] <= target) {
                // cout << matrix[midy][midx] << ' ' ; 
                if (matrix[midy][midx] == target) {
                    return true; 
                }
                ++midx; 
            }
            // cout << matrix[midy][midx] << ' ' ; 
            // cout << endl; 
            return bsearch(x0, midy + 1, midx - 1, y1) || bsearch(midx, y0, x1, midy - 1); 
        };
        return bsearch(0, 0, matrix[0].size() - 1, matrix.size() - 1); 
    }
    
    
    
    
};