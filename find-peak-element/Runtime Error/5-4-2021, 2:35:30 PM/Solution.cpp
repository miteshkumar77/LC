// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        int l = -1;
        int r = nums.size() - 1;
        int ans = -1;
        int mid;
        while(l < r) {
            mid = l + (r - l)/2;
            if (nums[mid] < nums[mid+1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};