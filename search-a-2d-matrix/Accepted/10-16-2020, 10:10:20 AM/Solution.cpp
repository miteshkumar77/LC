// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int l = 0;
        int r = matrix.size() * matrix[0].size() - 1;
        int m;
        int i;
        int j;
        while(l <= r) {
            m = l + (r - l)/2;
            i = m/matrix[0].size();
            j = m % matrix[0].size();
            cout << m << ' ' << i << ' ' << j << endl;
            if (matrix[i][j] > target) {
                r = m - 1;
            } else if (matrix[i][j] < target) {
                l = m + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};