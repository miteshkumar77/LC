// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]); 
            }
        }
        
        for (int i = 0; i < matrix.size(); ++i) {
            int L = 0; int R = matrix[i].size() - 1; 
            while(L < R) {
                swap(matrix[i][L++], matrix[i][R--]); 
            }
        }
    }
};