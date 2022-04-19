// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
       
        unordered_set<int> seen;
        seen.insert(0);
        int sum = 0;
        int ans = 0;
        for (int i : nums) {
            sum += i;
            if (seen.find(sum - target) != seen.end()) {
                ++ans;
                seen.clear();
            }
            seen.insert(sum);
        }
        return ans;
    }
};