// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0; 
        for (int x = 0; x * x + x <= 2 * N; ++x) {
            if ((2 * N - x * x - x) % (2 * x + 2) == 0) {
                ++ans; 
            }
        }
        return ans; 
    }
};