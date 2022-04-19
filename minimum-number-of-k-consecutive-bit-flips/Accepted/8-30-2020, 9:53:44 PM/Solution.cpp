// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        vector<bool> event(A.size() + 1, false);
        
        bool flipped = false; 
        int ans = 0; 
        
        for (int i = 0; i < A.size(); ++i) {
            if (event[i]) {
                flipped = !flipped; 
            }
            int curElem = A[i]; 
            if (flipped) {
                curElem = (curElem + 1) % 2; 
            }
            if (curElem == 0) {
                if (i + K > A.size()) {
                    return -1; 
                } else {
                    event[i + K] = true; 
                    ++ans; 
                    flipped = !flipped; 
                }
            }
            
        }
        return ans; 
    }
};