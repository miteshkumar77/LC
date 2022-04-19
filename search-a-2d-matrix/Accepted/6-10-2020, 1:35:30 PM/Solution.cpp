// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false; 
        }
        int L = 0; 
        int R = matrix.size() - 1; 
        int mid;  
        while(L <= R) {
            mid = L + (R - L)/2; 
            if (matrix[mid].back() > target && matrix[mid].front() > target) {
                R = mid - 1; 
            } else if (matrix[mid].back() < target && matrix[mid].front() < target) {
                L = mid + 1; 
            } else {
                L = 0; 
                R = matrix[0].size() - 1; 
                int i = mid; 
                while(L <= R) {
                    mid = L + (R - L)/2; 
                    if (matrix[i][mid] < target) {
                        L = mid + 1; 
                    } else if (matrix[i][mid] > target) {
                        R = mid - 1; 
                    } else {
                        return true; 
                    }
                }
                return false; 
            }
        }
        return false; 
    }
};