// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> seen;
        int ans = 0;
        // a - b = k
        // b - a = k;
        // a = b - k
        // a = b + k
        for (int i = 0; i < nums.size(); ++i) {
            if (k == 0) {
                if (seen.find(nums[i]) != seen.end() && seen[nums[i]] == 1) {
                    ++ans;
                }
            } else {
                if (seen.find(nums[i]) == seen.end()) {
                    if (seen.find(nums[i] - k) != seen.end()) {
                        ++ans;
                    }
                    if (seen.find(k + nums[i]) != seen.end()) {
                        ++ans;
                    }
                }
            }
            ++seen[nums[i]];
        }
        
        return ans;
    }
};