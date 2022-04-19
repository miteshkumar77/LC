// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int steps = 0; 
        int curr_idx = 0; 
        int maxdist = 0; 
        int nextmax = 0; 
        while(true) {
            if (nextmax >= nums.size() - 1) {
                return steps; 
            }
            for (int i = maxdist; i <= nextmax; ++i) {
                if (i + nums[i] > maxdist) {
                    maxdist = i + nums[i]; 
                }
            }
            
            ++steps;
            swap(maxdist, nextmax);  
        }
        
        return -200; 
    }
};