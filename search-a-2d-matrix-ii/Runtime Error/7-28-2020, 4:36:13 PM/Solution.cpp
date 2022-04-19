// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        
        
        function<int(int,int,int,int)> binSearch = [&](int iL, int jL, int iR, int jR) -> int {
            if (iL > iR || jL > jR) {
                return false;
            } else if (target < matrix[iL][jL] || target > matrix[iR][jR]) {
                return false;
            }
            
            
            int jM = jL + (jR - jL)/2; 
            int row = iL; 
            while(row <= iR && matrix[row][jM] <= target) {
                if (matrix[row][jM] == target) {
                    return true; 
                }
                ++row; 
            }
            
            return binSearch(iL, jM + 1, row - 1, jR) || binSearch(row, jL, iR, jM - 1);
            
        };
        
        
        return binSearch(0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }
    
    
    
    
};