// https://leetcode.com/problems/largest-sum-of-averages

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<int> pre(A.size() + 1); 
        pre[0] = 0; 
        for (int i = 0; i < A.size(); ++i) {
            pre[i + 1] = pre[i] + A[i]; 
        }
        
        function<double(int,int)> avg = [&](int L, int R) -> double {
            return ((double)pre[R + 1] - pre[L])/(R - L + 1); 
        };
        
        
        vector<vector<double>> dp(A.size(), vector<double>(K + 1)); 
        vector<vector<bool>> dp2(A.size(), vector<bool>(K + 1, false)); 
        
        function<double(int,int)> ans = [&](int i, int k) -> double {
            if (dp2[i][k]) {
                return dp[i][k]; 
            } 
            
            if (k == 1) {
                dp2[i][k] = true; 
                dp[i][k] = avg(i, A.size() - 1); 
                return dp[i][k]; 
            }
            
            double ret = 0; 
            for (int x = i; x < A.size() - 1; ++x) {
                ret = max(ret, avg(i, x) + ans(x + 1, k - 1)); 
            }
            dp2[i][k] = true; 
            dp[i][k] = ret; 
            return ret; 
        }; 
        return ans(0, K); 
    }
};