// https://leetcode.com/problems/the-kth-factor-of-n

class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 0; 
        int factor;
        for (factor = 1; factor <= n && i < k; ++factor) {
            if (n % factor == 0) {
                ++i;
            }
            // cout << factor << ' ' << i << endl;
            if (i >= k) {
                return factor;
            }

        }
        
        // if (i < k) {
            return -1;
        // }
        
        // return factor;
    }
};