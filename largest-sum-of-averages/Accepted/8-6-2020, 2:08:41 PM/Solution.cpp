// https://leetcode.com/problems/largest-sum-of-averages

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<int> pre(A.size() + 1); 
        pre[0] = 0; 
        for (int i = 0; i < A.size(); ++i) {
            pre[i + 1] = pre[i] + A[i]; 
        }
        
        
        vector<vector<vector<double>>> dp(A.size(), vector<vector<double>>(A.size(), vector<double>(K + 1))); 
        vector<vector<vector<bool>>> dp2(A.size(), vector<vector<bool>>(A.size(), vector<bool>(K + 1, false))); 

        function<double(int,int)> avg = [&](int L, int R) -> double {
            return ((double)pre[R + 1] - pre[L])/(R - L + 1); 
        };
        
        
        function <double(int,int,int)> ans = [&](int L, int R, int k) -> double {
            if (dp2[L][R][k]) {
                return dp[L][R][k]; 
            }
            if (k == 1) {
                dp[L][R][k] = avg(L, R); 
                dp2[L][R][k] = true; 
                return dp[L][R][k]; 
            }
            
            double ret = 0; 
            for (int i = L; i < R - k + 2; ++i) {
                ret = max(ret, ans(L, i, 1) + ans(i + 1, R, k - 1)); 
            }
            
            dp2[L][R][k] = true; 
            dp[L][R][k] = ret; 
            return ret; 
        };
        
        return ans(0, A.size() - 1, K); 
    }
};