// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> seen(n + 1, true);
        seen[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            for (int j = i+i; j <= n; j += i) {
                // if (!seen[j]) break;
                seen[j] = false;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += (int)(seen[i]);
            // cout << i << ": " << seen[i] << endl;
        }
        return ans;
        
    }
};