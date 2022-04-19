// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
        vector<int> ret;
        ret.push_back(0);
        ret.push_back(nums.size() - 1);
        
        if (nums.size() < 3) {
            return ret;
        }
        vector<int> nums2 = nums;
        sort(nums.begin(), nums.end());
        while (ret[0] != ret[1]) {
            if (nums[ret[0]] + nums[ret[1]] < target) {
                ret[0] += 1;
            } else if (nums[ret[0]] + nums[ret[1]] > target) {
                ret[1] -= 1;
            } else {
                break;
            }
            
            
        }
        
        ret[0] = distance(nums2.begin(), find(nums2.begin(), nums2.end(), nums[ret[0]]));
        vector<int>::iterator nth = nums2.begin() + ret[0]; 
        nums2.erase(nth);
        ret[1] = distance(nums2.begin(), find(nums2.begin(), nums2.end(), nums[ret[1]]));
        
        if (ret[0] <= ret[1]) {
            ret[1] += 1;
        }
        return ret;
    }
};