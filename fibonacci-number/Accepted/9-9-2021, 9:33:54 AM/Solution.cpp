// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        int a = 0; int b = 1;
        if (n == 0) return a;
        while(n--) {
            a = b + a;
            swap(a, b);
        }
        return a;
    }
};