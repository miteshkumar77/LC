// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int lb(vector<int> const& nums, int target, int add, bool lb, int l) {
        int r = nums.size(); --r; int ans = lb ? l : r;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] + add > target)
            {
                if (!lb) ans = mid;
                r = mid - 1;
            } else if (nums[mid] + add < target)
            {
                if (lb) ans = mid;
                l = mid + 1;
            } else {
                ans = mid;
                if (lb) r = mid - 1;
                else l = mid + 1;
            }
        }
        return nums[ans]; 
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        bool set = false;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i+2 < n; ++i) {
            for (int j = i+1; j + 1 < n; ++j) {
                int a = lb(nums, target, nums[i] + nums[j], true, j+1) + nums[i] + nums[j];
                int b = lb(nums, target, nums[i] + nums[j], false, j+1) + nums[i] + nums[j];
                if (!set || abs(target - a) < abs(target - ans)) {
                    set = true;
                    ans = a;
                }
                if (abs(target - b) < abs(target - ans)) {
                    ans = b;
                }
            }
        }
        return ans;
    }
};