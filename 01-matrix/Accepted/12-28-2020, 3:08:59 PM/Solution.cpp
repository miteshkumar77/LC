// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = INT_MAX - 100;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
                } else if (j == 0) {
                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + 1);
                } else {
                    matrix[i][j] = min(matrix[i][j], min(matrix[i - 1][j], matrix[i][j - 1]) + 1);
                }
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) continue;
                if (i == m - 1) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j + 1] + 1);
                } else if (j == n - 1) {
                    matrix[i][j] = min(matrix[i][j], matrix[i + 1][j] + 1);
                } else {
                    matrix[i][j] = min(matrix[i][j], min(matrix[i + 1][j], matrix[i][j + 1]) + 1); 
                }
            }
        }
        return matrix;
    }
};