// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int f) {
        long long k = 1;
        long long n = f;
        int ans = 0;
        while(true) {
            long long num = 2 * n + k - k * k;
            if (num > 0 && num % (2 * k) == 0) {
                ++ans;
            } else if (num <= 0) {
                break;
            }
            ++k;
        }
        return ans;
    }
};