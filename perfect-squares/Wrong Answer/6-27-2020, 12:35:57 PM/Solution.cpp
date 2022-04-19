// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        vector<int> dists(n + 1, INT_MAX);
        dists[0] = 0; 
        for (int i = 1; i <= n/2; ++i) {
            int plus = i * i; 
            for (int x = 0; x <= n; ++x) {
                if (dists[x] != INT_MAX && x + plus <= n) {
                    dists[x + plus] = min(dists[x + plus], dists[x] + 1); 
                }
            }
        }
        return dists.back(); 
    }
};