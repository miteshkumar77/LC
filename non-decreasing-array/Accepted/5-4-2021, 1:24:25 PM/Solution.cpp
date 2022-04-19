// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        array<int, 3> p;
        p[1] = INT_MIN;
        p[2] = INT_MIN;
        int changes = 0;
        for (int i = 0; i < n; ++i) {
            p[0] = p[1]; p[1] = p[2]; p[2] = nums[i];
            if (p[2] < p[1]) {
                if (p[0] <= p[2]) {
                    p[1] = p[0];
                } else {
                    p[2] = p[1];
                }
                ++changes;
            }
            if (changes > 1) return false;
        }
        return true;
    }
};