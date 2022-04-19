// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size(), 0); 
        int L = 0; 
        int R = A.size() - 1; 
        for (int i = A.size() - 1; i >= 0; --i) {
            if (abs(A[L]) > abs(A[R])) {
                ans[i] = A[L] * A[L++]; 
            } else {
                ans[i] = A[R] * A[R--]; 
            }
        }
        return ans; 
        
    }
};