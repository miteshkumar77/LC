// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 1; i < A.size(); ++i) {
            for (int j = max(0, i - 3); j < i; ++j) {
                if (A[i] == A[j]) return A[i];
            }
        }
        return 0;
    }
};