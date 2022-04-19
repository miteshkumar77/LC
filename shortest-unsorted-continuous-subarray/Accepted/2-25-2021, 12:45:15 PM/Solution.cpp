// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = n;
        int r = -1;
        int maxseen = INT_MIN;
        int minseen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < maxseen) {
                r = i;
            } else {
                maxseen = nums[i];
            }
        }
        
        for (int j = n - 1; j >= 0; --j) {
            if (nums[j] > minseen) {
                l = j;
            } else {
                minseen = nums[j]; 
            }
        }
        if (r <= l) return 0;
        return r - l + 1;
        
    }
};