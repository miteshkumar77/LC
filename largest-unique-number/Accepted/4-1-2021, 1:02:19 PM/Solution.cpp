// https://leetcode.com/problems/largest-unique-number

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        int prev = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (i + 1 == n) {
                if (i == 0 || A[i] != A[i - 1]) {
                    return A[i];
                }
            } else if (i == 0) {
                if (A[i] != A[i + 1]) {
                    return A[i];
                }
            } else {
                if (A[i] != A[i + 1] && A[i] != A[i - 1]) {
                    return A[i];
                }
            }
        }    
        return -1;
    }
};