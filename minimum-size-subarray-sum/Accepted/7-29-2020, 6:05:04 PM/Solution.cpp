// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int runningSum = 0; 
        int len = INT_MAX;
        bool found_len = false; 
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i]; 
            while(j <= i && runningSum >= s) {
                found_len = true; 
                runningSum -= nums[j]; 
                if (i - j + 1 < len) {
                    len = i - j + 1; 
                }
                ++j;
            }
        }
        if (found_len) {
            return len;
        } else {
            return 0; 
        }
    }
};