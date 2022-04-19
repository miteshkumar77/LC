// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> P(A.size() + 1);
        P[0] = 0; 
        for (int i = 1; i <= A.size(); ++i) {
            P[i] += P[i - 1] + A[i - 1]; 
        }
        
        int ans = A.size() + 1; 
        deque<int> mq; 
        mq.push_back(0); 
        for (int i = 1; i < P.size(); ++i) {
            if (P[i] >= K) {
                ans = min(ans, i);
            }
            
            while(mq.size() > 0 && P[i] - P[mq.front()] >= K) {
                ans = min(ans, i - mq.front()); mq.pop_front(); 
            }
            
            while(mq.size() > 0 && P[i] <- P[mq.back()]) {
                mq.pop_back(); 
            }
            mq.push_back(i);
        }
        if (ans <= A.size()) {
            return ans; 
        } else {
            return -1; 
        }
    }
    
    
    
};