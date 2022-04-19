// https://leetcode.com/problems/count-special-quadruplets

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans = 0;
        for (int d = 0; d < nums.size(); ++d) {
            for (int c = 0; c < d; ++c) {
                for (int b = 0; b < c; ++b) {
                    for (int a = 0; a < c; ++a) {
                        if (nums[a] + nums[b] + nums[c] == nums[d]) ++ans;
                    }
                }
            }
        }
        return ans;
    }
};