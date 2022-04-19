// https://leetcode.com/problems/array-nesting

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            int s = 0;
            while(nums[j] >= 0) {
                int tmp = nums[j];
                nums[j] = -1;
                j = tmp;
                ++s;
            }
            ans = max(ans, s);
        }
        return ans;
    }
};