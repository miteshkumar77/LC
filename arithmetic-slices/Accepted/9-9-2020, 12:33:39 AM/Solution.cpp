// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int pre = 0;
        int ans = 0; 
        int nxt = 0; 
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                nxt = pre + 1; 
                ans += nxt; 
                pre = nxt; 
            } else {
                pre = 0; 
            }
        }
        return ans; 
    }
};