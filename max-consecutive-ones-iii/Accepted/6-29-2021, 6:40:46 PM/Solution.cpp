// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int n = nums.size();
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            zeros += (nums[i] == 0);
            while(j <= i && zeros > k) {
                zeros -= (nums[j++] == 0);
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};