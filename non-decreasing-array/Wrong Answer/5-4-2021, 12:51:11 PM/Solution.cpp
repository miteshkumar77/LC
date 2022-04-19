// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int prev = INT_MIN;
        int changes = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < prev) {
                ++changes;
                if (changes > 1) return false;
            } else {
                prev = nums[i];
            }
        }    
        return true;

    }
};