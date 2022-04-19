// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    
    int mult(int x, int y) {
        int a = 0;
        
        while(y) {
            if (y&1) {
                --y;
                if (INT_MAX - a < x) {
                    return INT_MAX;
                }
                a = (x + a);
            } else {
                y >>= 1;
                if (INT_MAX - x < x) {
                    return INT_MAX;
                }
                x = x + x;
            }
        }
        
        return a;
    }
    
    int divide(int dividend, int divisor) {
        
        if (dividend == INT_MIN) {
            return divide(dividend + 1, divisor) + divide(-1, divisor); 
        }
        
        int sign = 1;
        if (dividend < 0) sign = (sign + 1) % 2;
        if (divisor < 0) sign = (sign + 1) % 2;
        
        if (dividend < 0) {
            dividend = dividend - dividend - dividend;
        }
        if (divisor < 0) {
            divisor = divisor - divisor - divisor;
        }
        int ans = 0;
        
        int l = 1;
        int r = dividend;
        int mid;
        while(l <= r) {
            mid = l + ((r - l)>>1);
            if (mult(divisor, mid) > dividend) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        return sign?ans:ans - ans - ans;
        
    }
};