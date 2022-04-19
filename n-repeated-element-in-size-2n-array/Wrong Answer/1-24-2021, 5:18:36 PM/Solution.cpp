// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 3; i < A.size(); ++i) {
            if (A[i] == A[i - 1] || A[i] == A[i - 2] || A[i] == A[i - 3]) {
                return A[i];
            }
        }
        return 0;
    }
};