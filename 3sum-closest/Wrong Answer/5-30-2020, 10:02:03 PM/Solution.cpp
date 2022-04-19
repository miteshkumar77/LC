// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end()); 
        int closest_sum = nums[0] + nums[1] + nums[2]; 
        for (int i = 0; i < nums.size(); ++i) {
            int lo = i + 1; 
            int hi = nums.size() - 1; 
            while(lo < hi) {
                if (abs(nums[lo] + nums[hi] + nums[i] - target) < abs(closest_sum - target)) {
                    closest_sum = nums[lo] + nums[hi] + nums[i]; 
                }
                if (nums[i] + nums[lo] + nums[hi] > target) {
                    ++lo; 
                } else if (nums[i] + nums[lo] + nums[hi] < target) {
                    --hi; 
                } else {
                    return target; 
                }
            }
        }
        return closest_sum; 
        
        
    }
};