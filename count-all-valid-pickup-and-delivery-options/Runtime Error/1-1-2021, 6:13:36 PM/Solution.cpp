// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

class Solution {
public:
    
    int countOrders(int n) {
        int M = 1e9 + 7;
        int ans = 1;
        
        for (int i = 1; i <= n; ++i) {
            int positions = (i - 1) * 2 + 1;
            int ways = 0;
            for (int j = 0; j < positions; ++j) {
                ways += positions - j;
                ways = ways % M;
            }
            ans = (ans * ways) % M;
        }
        return ans;
    }
};