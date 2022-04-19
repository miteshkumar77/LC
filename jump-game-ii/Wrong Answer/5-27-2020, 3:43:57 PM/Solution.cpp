// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
    int steps = 0; 
    int max_reachable = 0; 
    for (int i = 0; i < nums.size(); ++i) {
        if (i > max_reachable) {
            return -1; 
        }
        
        if (nums[i] + i > max_reachable) {
            max_reachable = nums[i] + i; 
            ++steps; 
        }
        
        if (nums[i] + i >= nums.size() - 1) {
            return steps; 
        }
    }
        
    return steps; 
        
    }
};