// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        
        int L0 = 0;
        int R0 = matrix.size() - 1; 
        
        while(L0 <= R0) {
            int mid = L0 + (R0 - L0)/2; 
            if (matrix[mid].front() <= target && matrix[mid].back() >= target) {
                int L1 = 0; 
                int R1 = matrix[mid].size(); 
                
                while(L1 <= R1) {
                    int mid1 = L1 + (R1 - L1)/2; 
                    if (matrix[mid][mid1] > target) {
                        R1 = mid1 - 1; 
                    } else if (matrix[mid][mid1] < target) {
                        L1 = mid1 + 1; 
                    } else {
                        return true; 
                    }
                }
                return false; 
                
            } else if (matrix[mid].front() > target) {
                R0 = mid - 1;
            } else {
                L0 = mid + 1; 
            }
        }
        return false; 
    }
};