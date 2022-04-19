// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        int sum = 0; 
        int ans = 0; 
        unordered_set<int> seen; 
        seen.insert(0); 
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i]; 
            if (seen.find(sum - target) != seen.end()) {
                seen = unordered_set<int>(); 
                ++ans; 
                sum = 0; 
            } 
            seen.insert(sum); 
        }
        return ans; 
    }
};