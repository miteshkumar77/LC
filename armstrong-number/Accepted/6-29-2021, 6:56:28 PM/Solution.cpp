// https://leetcode.com/problems/armstrong-number

class Solution {
public:
    int digs(int n) {
        return n == 0 ? 0 : 1 + digs(n/10);
    }
    int powr(int b, int e) {
        if (e == 0) return 1;
        return b * pow(b, e - 1);
    }
    
    bool isArmstrong(int n) {
        int ans = 0;
        int acc = n;
        int pow = 1e8;
        int dig = digs(n);
        while(pow > 0) {
            ans += powr(acc/pow, dig);
            if (ans > n) return false;
            acc %= pow;
            pow /= 10;
        }
        return ans == n;
    }
};