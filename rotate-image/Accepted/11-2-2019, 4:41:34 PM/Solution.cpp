// https://leetcode.com/problems/rotate-image

#include <algorithm>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix.size(); j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size()/2; j++) {
                std::swap(matrix[i][j], matrix[i][matrix.size() - j - 1]);
            }
        }
    }
};