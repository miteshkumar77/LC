// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        // a, b, target - a = b -> a + b = target
        // find b
        for (int i = 0; i < nums.size(); ++i) {
            if (seen.find(target - nums[i]) != seen.end()) {
                return vector<int>{seen[target - nums[i]], i};
            }
            seen[nums[i]] = i;
        }
        return vector<int>();
    }
};