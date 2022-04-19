// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false; .
        }
        int L = 0; 
        int R = matrix.size() * matrix[0].size() - 1; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            pair<int, int> effective_mid (mid/matrix[0].size(), mid % matrix[0].size()); 
            if (matrix[effective_mid.first][effective_mid.second] < target) {
                L = mid + 1; 
            } else if (matrix[effective_mid.first][effective_mid.second] > target) {
                R = mid - 1; 
            } else {
                return true; 
            }
        }
        return false; 
    }
};