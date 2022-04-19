// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        vector<int> ret;
        while(i != j) {
            if (nums[i] + nums[j] < target) {
                i += 1;
                
            } else if (nums[i] + nums[j] > target) {
                j -= 1;
                
            } else {
                ret.push_back(i);
                ret.push_back(j);
                return ret;
            }
            
            
        }
        
        return ret;
    }
};