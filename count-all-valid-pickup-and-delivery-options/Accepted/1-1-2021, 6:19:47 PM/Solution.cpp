// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

class Solution {
public:
    typedef unsigned long long int ulli;
    int countOrders(int n) {
        ulli M = 1e9 + 7;
        ulli ans = 1;
        
        for (ulli i = 1; i <= n; ++i) {
            ulli positions = (i - 1) * 2 + 1;
            ulli ways = 0;
            for (ulli j = 0; j < positions; ++j) {
                ways += positions - j;
                ways = ways % M;
            }
            
            if (ways % 2 == 0) {
                ans = ((ans * (ways/2)) % M * 2) % M;
            } else {
                ans = (((ans * (ways/2)) % M * 2) % M + ans) % M;
            }
        }
        return ans;
    }
};