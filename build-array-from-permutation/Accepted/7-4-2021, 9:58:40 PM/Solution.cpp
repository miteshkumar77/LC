// https://leetcode.com/problems/build-array-from-permutation

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = nums[nums[i]];
        }
        return a;
    }
};