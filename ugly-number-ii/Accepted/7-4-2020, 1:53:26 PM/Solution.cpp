// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    typedef unsigned long long int ulli; 
    int nthUglyNumber(int n) {
        priority_queue<ulli, vector<ulli>, greater<ulli> > pq; 
        unordered_set<ulli> visited; 
        if (n == 0) {
            return 0; 
        }
        pq.push(1); 
        
        array<int, 3> dirs {2, 3, 5}; 
        for (int i = 1; i < n; ++i) {
            ulli t = pq.top(); 
            pq.pop(); 
            for (int j = 0; j < 3; ++j) {
                ulli cand = t * dirs[j]; 
                if (visited.find(cand) == visited.end()) {
                    pq.push(cand); 
                    visited.insert(cand); 
                }
            }
        }
        
        return pq.top(); 
    }
};