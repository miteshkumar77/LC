// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxjump = -1;
        int maxset = -1;
        int jumps = -1;        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxjump) {
                maxjump = maxset;
                maxset = 0;
                ++jumps;
            }
            maxset = max(maxset, nums[i] + i);
        }
        return jumps;
    }
};





































