// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = (n - k%n) % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
    }
};