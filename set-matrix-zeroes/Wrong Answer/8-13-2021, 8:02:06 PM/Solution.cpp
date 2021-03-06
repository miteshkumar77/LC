// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); int m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = -1;
                    matrix[i][0] = -1;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[0][j] == -1 || matrix[i][0] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[0][j] == -1 || matrix[i][0] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};