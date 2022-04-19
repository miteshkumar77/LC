// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // prefix + suffix = x
        // prefix? = x - suffix
        int suffix = accumulate(nums.begin(), nums.end(), 0);
        
        if (suffix == x) {
            return nums.size();
        }
        
        if (suffix < x) {
            return -1;
        }
        
        int prefix = 0;
        int ans = INT_MAX;
        unordered_map<int, int> seen_prefixes{{0, 0}};
        for (int i = 0; i < nums.size(); ++i) {
            if (seen_prefixes.find(x - suffix) != seen_prefixes.end()) {
                ans = min(ans, (int)(seen_prefixes[x - suffix] + nums.size() - i)); 
            }
            suffix -= nums[i];
            prefix += nums[i];
            seen_prefixes.insert(make_pair(prefix, i + 1));
        }
        return ans == INT_MAX?-1:nums.size() - ans;
        
    }
};