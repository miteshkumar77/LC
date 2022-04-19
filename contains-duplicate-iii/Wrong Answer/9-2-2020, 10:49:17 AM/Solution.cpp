// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0) {
            return 0; 
        }
        
        if (k == 0) {
            return t == 0; 
        }
        map<int, int> mp;
        // mp[nums[0]] = 1; 
        for (int i = 0; i < nums.size(); ++i) {
            auto ub = mp.lower_bound(nums[i]); 
            if (ub != mp.end()) {
                if (abs(ub -> first - nums[i]) <= t) {
                    return true; 
                }
            }
            if (ub != mp.begin()) {
                ub = prev(ub); 
                if (abs(ub -> first - nums[i]) <= t) {
                    return true; 
                }
            }
            
            ++mp[nums[i]]; 
            if (i >= k) {
                // cout << i << endl; 
                --mp[nums[i - k]]; 
                if (mp[nums[i - k]] == 0) {
                    mp.erase(nums[i - k]); 
                }
            }
        }
        return false; 
    }
};