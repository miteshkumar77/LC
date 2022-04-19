// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        array<int, 32> b{};
        long long pow;
        for (int i : nums) {
            pow = 1;
            for (int x = 0; x < 32; ++x, pow <<= 1) {
                if (pow&((long long)i)) {
                    b[x] = (b[x]+1)%3;
                }
            }
        }
        pow = 1;
        int ans = 0;
        for (int x = 0; x < 32; ++x, pow <<= 1) {
            if (b[x]) {
                ans |= pow;
            }
        }
        return ans;
    }
};