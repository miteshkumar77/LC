// https://leetcode.com/problems/sparse-matrix-multiplication

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<vector<int>> mat3(mat1.size(), vector<int>(mat2[0].size(), 0));
        vector<vector<array<int, 2>>> rows(mat3.size());
        vector<vector<array<int, 2>>> cols(mat3[0].size());
        
        for (int i = 0; i < mat1.size(); ++i) {
            for (int j = 0; j < mat1[0].size(); ++j) {
                if (mat1[i][j] != 0) {
                    rows[i].push_back({j, mat1[i][j]});
                }
            }
        }
        
        for (int i = 0; i < mat2.size(); ++i) {
            for (int j = 0; j < mat2[0].size(); ++j) {
                if (mat2[i][j] != 0) {
                    cols[j].push_back({i, mat2[i][j]});
                }
            }
        }
        for (int i = 0; i < mat3.size(); ++i) {
            for (int j = 0; j < mat3[0].size(); ++j) {
                int k1 = 0; int k2 = 0;   
                while(k1 < rows[i].size() && k2 < cols[j].size()) {
                    if (rows[i][k1][0] == cols[j][k2][0]) {
                        mat3[i][j] += rows[i][k1][1] * cols[j][k2][1];
                    }
                    if (rows[i][k1][0] < cols[j][k2][0]) ++k1; else ++k2;
                }
            }
        }
        return mat3;
    }
};