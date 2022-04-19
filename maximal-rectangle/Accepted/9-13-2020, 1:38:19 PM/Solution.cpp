// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    typedef array<int, 2> pii; 
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0; 
        }
        int ans = 0; 
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size(), 0)); 
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i - 1][j] == '1') {
                    dp[i][j] = dp[i - 1][j] + 1; 
                }
                
            }
            // cout << helper(dp[i]) << endl; 
            ans = max(ans, helper(dp[i])); 
        }
        
        
//         for (auto v : dp) {
//             for (auto i : v) cout << i << ' ';
//             cout << endl; 
//         }
        
//         for (auto v : dp) {
//             cout << helper(v) << endl; 
//         }
        return ans; 
 
    }
    
    
    int helper(vector<int> A) {
        vector<int> a1 = oneWay(A); 
        reverse(A.begin(), A.end()); 
        vector<int> a2 = oneWay(A); 
        reverse(a1.begin(), a1.end());
        // for (int i : a1) cout << i << ' ';
        // cout << endl; 
        // for (int i : a2) cout << i << ' ';
        // cout << endl; 
        int gans = 0; 
        for (int i = 0; i < A.size(); ++i) {
            gans = max(gans, a1[i] + a2[i] - A[i]); 
        }
        return gans; 
    }
    
    
    vector<int> oneWay(vector<int>& A) {
        vector<int> ret(A.size()); 
        stack<pii> stk; 
        for (int i = 0; i < A.size(); ++i) {
            pii cur{A[i], 1}; 
            while(!stk.empty() && cur[0] <= stk.top()[0]) {
                cur[1] += stk.top()[1]; 
                stk.pop(); 
            }
            stk.push(cur); 
            ret[i] = cur[0] * cur[1]; 
        }
        return ret; 
    }
    
};