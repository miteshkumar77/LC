// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1; 
        int R = n; 
        int ans = -1; 
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            
            if (isBadVersion(mid)) {
                R = mid - 1; 
                ans = mid; 
            } else {
                L = mid + 1; 
            }
        }
        
        return ans; 
    }
};