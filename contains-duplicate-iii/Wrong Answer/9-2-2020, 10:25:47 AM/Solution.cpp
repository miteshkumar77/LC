// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> mp;
        mp[nums[0]] = 1; 
        for (int i = 1; i < nums.size(); ++i) {
            auto lb = mp.lower_bound(nums[i]); 
            if (lb != mp.end()) {
                if (abs(lb -> second - nums[i]) <= t) {
                    return true; 
                }
            }
            auto ub = mp.upper_bound(nums[i]); 
            if (ub != mp.end()) {
                if (abs(ub -> second - nums[i]) <= t) {
                    return true; 
                }
            }
            
            ++mp[nums[i]]; 
            if (i >= k) {
                --mp[nums[i - k]]; 
                if (mp[nums[i - k]] == 0) {
                    mp.erase(nums[i - k]); 
                }
            }
        }
        return false; 
    }
};