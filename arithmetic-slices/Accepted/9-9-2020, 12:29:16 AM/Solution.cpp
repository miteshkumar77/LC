// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size(), 0); 
        int ans = 0; 
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] += dp[i - 1] + 1; 
            }
            ans += dp[i]; 
        }
        return ans; 
    }
};