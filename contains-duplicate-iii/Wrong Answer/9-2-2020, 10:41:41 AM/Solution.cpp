// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0) {
            return 0; 
        }
        map<int, int> mp;
        mp[nums[0]] = 1; 
        for (int i = 1; i < nums.size(); ++i) {
            auto lb = mp.lower_bound(nums[i]); 
            
            if (lb != mp.end() && prev(lb) != mp.end()) {
                lb = prev(lb); 
                if (abs(lb -> first - nums[i]) <= t) {
                    // cout << lb -> second << ' ' << nums[i] << endl; 
                    return true; 
                }
            }
            auto ub = mp.upper_bound(nums[i]); 
            if (ub != mp.end()) {
                if (abs(ub -> first - nums[i]) <= t) {
                    // cout << ub -> second << ' ' << nums[i] << endl; 
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