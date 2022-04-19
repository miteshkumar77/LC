// https://leetcode.com/problems/sparse-matrix-multiplication

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans(A.size(), vector<int>(B[0].size())); 
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B[0].size(); ++j) {
                for (int k = 0; k < B.size(); ++k) {
                    ans[i][j] += A[i][k] * B[k][j]; 
                }
            }
        }
        return ans; 
    }
};