// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        int i, j;
        for (int d = 0; d < m + n - 1; ++d) {
            if (d < m) {
                i = m - d - 1;
                j = 0;
            } else {
                i = 0;
                j = d - m; 
            }
            vector<int> tmp; tmp.reserve(n);
            while(i < m && j < n) {
                tmp.push_back(matrix[i][j]);
                ++i;
                ++j;
            }
            sort(tmp.begin(), tmp.end());
            int p = (int)tmp.size() - 1;
            while(p >= 0) {
                matrix[--i][--j] = tmp[p--];
            }
        }
        return matrix;
    }
};