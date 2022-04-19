// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(); 
        if (n < 3) return 0;
        int dp = 2;
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2])) {
                ans += ++dp - 2;
            } else {
                dp = 2;
            }
        }
        return ans;
    }
};