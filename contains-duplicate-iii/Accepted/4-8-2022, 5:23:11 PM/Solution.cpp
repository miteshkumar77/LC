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
            if (it != prev(ct.end()) && ((long long)next(it)->first - (long long)nums[i]) <= (long long)t)
                return true;
            if (it != ct.begin() && ((long long)nums[i] - (long long)prev(it)->first) <= (long long)t) {
                return true;
            }
        }
        return false;
    }
};