// https://leetcode.com/problems/minimum-operations-to-make-array-equal

class Solution {
public:
    int minOperations(int n) {
        int L = 0; 
        int R = n - 1; 
        int ans = 0; 
        while(L < R) {
            // cout << 2 * R + 1 << ' ' << 2 * L + 1 << endl; 
            ans += (((2 * R + 1) - (2 * L + 1)))/2; 
            ++L;
            --R; 
        }
        return ans; 
    }
};