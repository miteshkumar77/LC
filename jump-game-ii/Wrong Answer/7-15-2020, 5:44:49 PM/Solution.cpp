// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 1; 
        int i = 0; 
        int curr_max = nums[0];
        int next_max = nums[0]; 
        while(i < nums.size() - 1) {
            next_max = max(next_max, nums[i] + i);
            if (i == curr_max) {
                jumps += 1; 
                curr_max = next_max; 
            }
            i += 1; 
        }
        return jumps; 
    }
};