// https://leetcode.com/problems/rotate-image

#include <algorithm>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> mat2; 
        vector<int> tmp;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                
                if (j >= mat2.size()) {
                    mat2.push_back(tmp);
                }
                
                mat2[j].insert(mat2[j].begin(), matrix[i][j]); 
            }
        }
        
        matrix = mat2;
    }
};