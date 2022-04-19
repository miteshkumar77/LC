// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_dist = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] + i > max_dist) {
                max_dist = nums[i] + i; 
            }
            
            else if (nums[i] + i == max_dist) {
                break; 
            }
        }
        
        cout << max_dist; 
        return max_dist >= nums.size() - 1; 
    }
};