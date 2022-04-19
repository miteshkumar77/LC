// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int amt = 0; 
        int amt2 = nums[0]; 
        int tmp; 
        for (int i = 1; i < nums.size(); ++i) {
            tmp = amt2; 
            amt2 = max(amt + nums[i], amt2);
            amt = tmp;
        }
        return amt2; 
    }
};