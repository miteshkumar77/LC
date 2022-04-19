// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int R = x/2 + 1; 
        int L = 0; 
        int ans = -1; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            
            if ((unsigned long long int)mid * mid > x) {
                R = mid - 1; 
            } else if (mid * mid < x) {
                L = mid + 1; 
                ans = mid; 
            } else {
                return mid; 
            }
        }
        return ans; 
    }
};