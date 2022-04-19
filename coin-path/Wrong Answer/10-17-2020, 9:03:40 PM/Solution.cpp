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
        prev[0] = -1;
        
        cost[0] = A[0];
        
        for (int i = 1; i < n; ++i) {
            if (A[i] == -1) continue;
            int s = max(0, i - B);
            for (int j = s; j < i; ++j) {
                if (cost[j] != INT_MAX && cost[j] + A[i] < cost[i]) {
                    cost[i] = cost[j] + A[i];
                    prev[i] = j;
                }
            }
        }
        
        if (cost[n - 1] == INT_MAX) {
            return vector<int>();
        }
        
        int i = n - 1;
        vector<int> ans;
        while(i != -1) {
            ans.push_back(i + 1);
            i = prev[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};