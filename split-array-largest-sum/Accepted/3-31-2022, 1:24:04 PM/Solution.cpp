// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    bool check(vector<int>& nums, int m, int t) {
        int n = nums.size();
        int acc = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > t) return false;
            if ((acc += nums[i]) > t) {
                if (--m == 0) return false;
                acc = nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int mid;
        while(l < r) {
            mid = l + (r - l)/2;
            if (check(nums, m, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};