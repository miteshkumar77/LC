// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L = 0; int R = matrix.size() - 1; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            
            int res = matrix[mid][binSearch(matrix[mid], 0, matrix[mid].size() - 1, target)]; 
            if (res > target) {
                R = mid - 1; 
            } else if (res < target) {
                L = mid + 1; 
            } else {
                return true;
            }
        }
        return false; 
    }
    
    
    int binSearch(vector<int>& B, int L, int R, int target) {
        while(L < R) {
            // cout << L << ' ' << R << endl; 
            int mid = L + (R - L)/2; 
            if (B[mid] > target) {
                R = mid - 1; 
            } else if (B[mid] < target) {
                L = mid + 1; 
            } else {
                return mid; 
            }
        }
        return L; 
    }
    
    
};