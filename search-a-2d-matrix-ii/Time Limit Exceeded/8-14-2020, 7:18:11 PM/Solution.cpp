// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        
        
        
        function<bool(int,int,int,int)> bsearch = [&](int x0, int y0, int x1, int y1) -> bool {
            if (x0 > x1 || y0 > y1) {
                return false; 
            }
            
            
            int mid = y0 + (y1 - y0)/2; 
            int midx = x0; 
            
            if (matrix[mid][midx] == target) {
                return true; 
            }
            for (int i = x0 + 1; i <= x1; ++x1) {
                if (matrix[mid][i] == target) {
                    return true; 
                }
                
                if (matrix[mid][i] > target && matrix[mid][i - 1] < target) {
                    midx = i; 
                    break;
                }
            }
            
            return bsearch(x0, mid + 1, midx - 1, y1) || (midx, y0, x1, mid - 1); 
        };
        return bsearch(0, 0, matrix[0].size(), matrix.size()); 
    }
    
    
    
    
};