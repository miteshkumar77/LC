// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> ct;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > k) {
                if (--ct[nums[i-k-1]] == 0) {
                    ct.erase(nums[i-k-1]);
                }
            }
            ++ct[nums[i]];
            auto it = ct.find(nums[i]);
            if (it->second > 1) {
                return true;
            }
            if (it != prev(ct.end()) && (next(it)->first - nums[i]) <= t)
                return true;
            if (it != ct.begin() && (nums[i] - prev(it)->first) <= t) {
                return true;
            }
        }
        return false;
    }
};