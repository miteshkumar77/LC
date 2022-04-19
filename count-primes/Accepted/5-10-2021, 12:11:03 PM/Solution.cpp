// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        if (n == 0) return 0;
        vector<bool> seen(n + 1, true);
        seen[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (!seen[i]) continue;
            for (int j = i+i; j <= n; j += i) {
                seen[j] = false;
            }
        }
        return accumulate(seen.begin() + 1, seen.end() - 1, 0);
    }
};