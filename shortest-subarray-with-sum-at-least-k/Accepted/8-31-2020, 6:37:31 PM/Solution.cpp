// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        
        vector<int> P(A.size() + 1); 
        P[0] = 0; 
        for (int i = 1; i <= A.size(); ++i) {
            P[i] = A[i - 1] + P[i - 1]; 
        }
        deque<int> dq; 
        dq.push_back(0); 
        int ans = INT_MAX; 
        for (int i = 1; i < P.size(); ++i) {
            while(!dq.empty() && P[i] - P[dq.back()] >= K) {
                ans = min(i - dq.back(), ans); 
                dq.pop_back(); 
            }
            
            while(!dq.empty() && P[i] <= P[dq.front()]) {
                dq.pop_front(); 
            }
            dq.push_front(i); 
        }
        
        if (ans == INT_MAX) {
            return -1; 
        }
        return ans; 
        
    }
    
    
    
};