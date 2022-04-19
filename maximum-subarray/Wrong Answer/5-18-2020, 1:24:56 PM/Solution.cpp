// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0; 
        int curr_sum = 0; 
        for (int num : nums) {
            curr_sum += num; 
            if (curr_sum < 0) {
                curr_sum = 0; 
            } else {
                if (curr_sum > max_sum) {
                    max_sum = curr_sum; 
                }
            }
        }
        return max_sum; 
    }
};