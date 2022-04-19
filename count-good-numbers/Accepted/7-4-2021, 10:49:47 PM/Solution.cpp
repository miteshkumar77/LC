// https://leetcode.com/problems/count-good-numbers

class Solution {
public:
    long long pow(long long b, long long e, long long M) {
        long long q = 1;
        while(e) {
            if (e & 1) {
                q = (q * b) % M;
                --e;
            } else {
                b = (b * b) % M;
                e /= 2;
            }
        }
        return q;
    }
    // 0 2 4 6 8
    int countGoodNumbers(long long n) {
        long long M = 1e9 + 7;
        long long P = 4;
        long long E = 5;
        return (pow(E, (n + n % 2)/2, M) * pow(P, n/2, M)) % M;
    }
};