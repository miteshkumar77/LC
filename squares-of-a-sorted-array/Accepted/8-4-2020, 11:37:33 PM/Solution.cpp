// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans; ans.reserve(A.size()); 
        int min = INT_MAX; 
        int L = 0; 
        int R = 0; 
        for (int i = 1; i < A.size(); ++i) {
            if (abs(A[L]) >= abs(A[i])) {
                L = i; 
            } else {
                break; 
            }
        }
        R = L + 1; 
        while(L >= 0 || R < A.size()) {
            if (L < 0) {
                ans.push_back(A[R] * A[R++]); 
            } else if (R >= A.size()) {
                ans.push_back(A[L] * A[L--]); 
            } else {
                if (A[L] * A[L] >= A[R] * A[R]) {
                    ans.push_back(A[R] * A[R++]);
                } else {
                    ans.push_back(A[L] * A[L--]); 
                }
            }
        }
        return ans; 
    }
};