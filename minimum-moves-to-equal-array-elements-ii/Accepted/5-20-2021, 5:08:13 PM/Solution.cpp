// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    typedef signed long long int slli;
    int minMoves2(vector<int>& nums) {
        slli n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = n - 1;
        int ans = 0;
        while(l < r) {
            ans += nums[r--] - nums[l++];
        }
        return ans;
    }
};