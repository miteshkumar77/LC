// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0; 
        }
        int ans = nums[0] ^ nums[1]; 
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                ans = max(ans, nums[i] ^ nums[j]); 
            }
        }
        return ans; 
    }
};