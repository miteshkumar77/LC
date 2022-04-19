// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev1 = -1e9;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - prev1 <= k) {
                    return false;
                }
                prev1 = i;
            }
        }
        return true;
    }
};