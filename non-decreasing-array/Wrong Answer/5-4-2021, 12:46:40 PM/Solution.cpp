// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       #if 0 
        int n = nums.size();
        vector<int> suff(n, 0);
        int prev = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            prev = min(prev, nums[i]);
            suff[i] = prev;
        }
        int pref = INT_MIN;
        int changes = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (!(pref <= nums[i] && nums[i] <= suff[i+1])) ++changes;
            if (changes > 1) return false;
        }
        return true;
        #endif
        int n = nums.size();
        int prev = INT_MIN;
        int changes = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < prev) ++changes;
            if (changes == 2) return false;
            prev = nums[i];
        }    
        return true;

    }
};