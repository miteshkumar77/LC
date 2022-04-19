// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 4) {
            return 0; 
        }
        int maxd = INT_MAX;
        for (int i = 1; i < 3; ++i) {
            for (int j = 1; j < 3 - i; ++j) {
                maxd = min(maxd, nums[nums.size() - 1 - j] - nums[i]);
            }
        }
        return maxd;
        
    }
};