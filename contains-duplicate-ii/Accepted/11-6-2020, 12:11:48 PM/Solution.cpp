// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        
        int idx = 0;
        for (int i : nums) {
            
            if (seen.find(i) != seen.end()) {
                return true;
            }
            seen.insert(i);
            if (seen.size() > k) {
                seen.erase(nums[idx - k]);
            }
            ++idx;
        }
        return false;
        
    }
};