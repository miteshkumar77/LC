// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if (A.size() == 0) {
            return 0; 
        }
        int g_ans = A[0]; 
        int cur_ans = A[0]; 
        for (int i = 1; i < A.size(); ++i) {
            cur_ans = max(A[i], cur_ans + A[i]);
            g_ans = max(g_ans, cur_ans); 
        }
        vector<int> suff_max(A.size()); 
        int n = A.size() - 1;
        int suff_sum = A[n]; 
        suff_max[n] = suff_sum; 
        for (int i = n - 1; i >= 0; --i) {
            suff_sum += A[i]; 
            suff_max[i] = max(suff_max[i + 1], suff_sum); 
        }
     
        int pref_sum = 0; 
        for (int i = 0; i < n; ++i) {
            pref_sum += A[i]; 
            g_ans = max(pref_sum + suff_max[i + 1], g_ans); 
        }
        return g_ans; 
        
    }
};