// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        int L = 0; 
        int R = num/2; 
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            
            if (mid * mid > num) {
                R = mid - 1; 
            } else if (mid * mid < num) {
                L = mid + 1; 
            } else {
                return true; 
            }
        }
        
        return false; 
    }
};