// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ret;
        ret.push_back(0);
        ret.push_back(nums.size() - 1);
        
        while (ret[0] != ret[1]) {
            if (nums[ret[0]] + nums[ret[1]] < target) {
                ret[0] += 1;
            } else if (nums[ret[0]] + nums[ret[1]] > target) {
                ret[1] -= 1;
            } else {
                return ret;
            }
            
            
        }
        
        return ret;
    }
};