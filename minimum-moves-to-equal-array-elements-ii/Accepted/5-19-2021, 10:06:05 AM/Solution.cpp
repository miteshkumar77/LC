// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    typedef signed long long int slli;
    int minMoves2(vector<int>& nums) {
        slli n = nums.size();
        sort(nums.begin(), nums.end());
        slli s = accumulate(nums.begin(), nums.end(), 0);
        slli p = 0;
        slli a = INT_MAX;
        /*
            i * nums[i] - p + s - (n - i - 1) * nums[i] = 
            s - p - (n - 2 * i - 1) * nums[i]
        */
        for (slli i = 0; i < n; ++i) {
            s -= nums[i];
            a = min(a, s - p - (n - 2 * i - 1) * nums[i]);
            p += nums[i];
        }
        return a;
    }
};