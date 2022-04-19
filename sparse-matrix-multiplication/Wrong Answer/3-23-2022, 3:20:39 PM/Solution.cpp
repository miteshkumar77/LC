// https://leetcode.com/problems/sparse-matrix-multiplication

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<vector<int>> mat3(mat1.size(), vector<int>(mat2[0].size(), 0));
        for (int i = 0; i < mat3.size(); ++i) {
            for (int j = 0; j < mat3[0].size(); ++j) {
                for (int k = 0; k < mat3[0].size(); ++k) {
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        return mat3;
    }
};