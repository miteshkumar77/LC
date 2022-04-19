// https://leetcode.com/problems/two-sum-less-than-k

class Solution {
public:
    
    
    
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int l = 0; int r = A.size() - 1;
        int ans = -1;
        while(l < r) {
            if (A[l] + A[r] < K) {
                ans = max(ans, A[l] + A[r]); 
                ++l;
            } else {
                --r;
            }
        }
        
        return ans;
    }
};