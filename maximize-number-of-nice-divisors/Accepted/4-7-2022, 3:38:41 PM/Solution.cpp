// https://leetcode.com/problems/maximize-number-of-nice-divisors

class Solution {
public:
    using ll = long long;
    ll powMod(ll base, ll exp, ll M, ll acc = (ll)1) {
        if (exp > 0) {
            if (exp & 1) {
                return powMod(base, exp - 1, M, (acc * (base % M)) % M);
            }
            return powMod((base * base)%M, exp >> 1, M, acc);
        }
        return acc;
    }
    int maxNiceDivisors(int pF) {
        ll numThrees = pF/3;
        if (numThrees) {
            ll tmp = (pF - ((numThrees - 1) * 3));
            if (tmp == 4) {
                --numThrees;
            }
        }
        
        pF -= (numThrees * 3);
        
        ll numTwos = pF/2;
        ll numXs = max(1, pF -= (numTwos * 2));
        ll M = 1e9 + 7;
        return (((powMod(3, numThrees, M) * powMod(2, numTwos, M)) % M) * numXs) % M;
    }
};