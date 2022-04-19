// https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j <= A[0].size()/2; ++j) {
                swap(A[i][j], A[i][A[0].size() - j - 1]); 
                A[i][j] = (A[i][j] + 1) % 2; 
                if (j != A[0].size()/2) {
                    A[i][A[0].size() - j - 1] = (A[i][A.size() - j - 1] + 1) % 2;
                }
            }
        }
        return A;
    }
};