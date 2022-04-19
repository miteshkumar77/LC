// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    
    bool check(vector<int>& nums, int t, int m) {
        int s = 1;
        int n = nums.size();
        int sm = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] + sm > t) {
                ++s;
                sm = nums[i];
                if (sm > t || s > m) return false;
            } else {
                sm += nums[i];
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l = 0;
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = r; int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(nums, mid, m)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};