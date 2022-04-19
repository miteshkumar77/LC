// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int i, j;
        while(true) {
            i = rand() % (A.size() - 1);
            j = rand() % (A.size() - i - 1) + i + 1;
            if (A[i] == A[j]) return A[i];
        }
        return 0;
    }
};