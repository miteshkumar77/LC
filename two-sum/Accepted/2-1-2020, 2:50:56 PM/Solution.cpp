// https://leetcode.com/problems/two-sum

#include <utility>
class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> remainder_indices;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int>::iterator tmp = remainder_indices.find(nums[i]);
            if (tmp != remainder_indices.end()) {
                vector<int> ret = {tmp -> second, i};
                return ret;
            } else {
                remainder_indices.insert(make_pair(target - nums[i], i));
            }
        }
        vector<int> ret = {-1, -1};
        return ret;
        
    }
};