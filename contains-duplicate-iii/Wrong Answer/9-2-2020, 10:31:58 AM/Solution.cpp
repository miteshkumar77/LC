// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> mp;
        mp[nums[0]] = 1; 
        for (int i = 1; i < nums.size(); ++i) {
            auto lb = mp.lower_bound(nums[i]); 
            if (lb != mp.end()) {
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
            if (i >= (k - 1)) {
                cout << i << endl; 
                --mp[nums[i - k + 1]]; 
                if (mp[nums[i - k + 1]] == 0) {
                    mp.erase(nums[i - k + 1]); 
                }
            }
        }
        return false; 
    }
};