// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        
        int original_n = n; 
        
        
        
        double ans = 1; 
        n = abs(n); 
        while(n > 0) {
            if (n & 1) {
                ans *= x; 
            }
            x *= x;
            n >>= 1; 
        }
        if (original_n < 0) {
            return 1/ans;
        } else {
            return ans; 
        }
        
    }
};