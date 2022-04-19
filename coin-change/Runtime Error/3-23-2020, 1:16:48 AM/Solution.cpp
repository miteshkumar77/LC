// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> nums(amount + 1, -1);
        nums[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            for (int c : coins) {
                if (i + c <= amount && (nums[i] != -1)) {
                    if (nums[i + c] == -1 || 
                       nums[i + c] > nums[i] + 1) {
                        nums[i + c] = nums[i] + 1;
                    }
                }
            }
        }
        return nums.back(); 
    }
};