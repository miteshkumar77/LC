// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> nums(amount + 1, 0); 
        for (int i = 0; i <= amount; ++i) {
            for (int c : coins) {
                if (i + c <= amount && (i == 0 || nums[i] != 0)) {
                    if (nums[i + c] == 0 || 
                       nums[i + c] > nums[i] + 1) {
                        nums[i + c] = nums[i] + 1;
                    }
                }
            }
        }
        cout << nums.back() << endl; 
        return (nums.back() == 0)?-1:nums.back(); 
    }
};