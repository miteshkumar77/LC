// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int L = 0; 
        int R = A.size() - 1; 
        
        while(L < R) {
            if (A[L] % 2 == 0) {
                ++L; 
            } else if (A[R] % 2 == 1) {
                --R; 
            } else {
                swap(A[L], A[R]); 
            }
        }
        return A; 
    }
};