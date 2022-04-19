// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long long int L = 0; 
        unsigned long long int R = num/2 + 1; 
        
        while(L <= R) {
            unsigned long long int mid = L + (R - L)/2; 
            
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