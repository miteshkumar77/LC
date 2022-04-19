// https://leetcode.com/problems/coin-path

class Solution {
public:
    typedef unsigned long long int ulli;
    vector<int> cheapestJump(vector<int>& A, int B) {
        if (A[0] == -1) {
            return vector<int>();
        }
        
        int n = A.size();
        vector<int> cost(n, INT_MAX);
        vector<int> prev(n);
        cost[n - 1] = A[n - 1];
        prev[n - 1] = n;
        
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] == -1) continue;
            
            int e = min(n - 1, i + B);
            
            for (int j = i + 1; j <= e; ++j) {
                if (cost[j] != INT_MAX && cost[j] + A[i] < cost[i]) {
                    cost[i] = cost[j] + A[i];
                    prev[i] = j;
                }
            }
        }
        
        if (cost[0] == INT_MAX) {
            return vector<int>();
        }
        
        int i = 0;
        vector<int> ans;
        while(i < n) {
            ans.push_back(i + 1);
            i = prev[i];
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};