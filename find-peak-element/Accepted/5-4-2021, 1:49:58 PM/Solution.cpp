// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    bool strictlyLessThan(int i, int j, const vector<int>& nums) {
        signed long long iv = (i == -1 || i == nums.size()) ? LLONG_MIN : nums[i];
        signed long long jv = (j == -1 || j == nums.size()) ? LLONG_MIN : nums[j];
        return iv < jv;
    }
    int findPeakElement(vector<int>& nums) {
        int l = -1;
        int r = nums.size();
        int ans = -1;
        int mid;
        while(l < r) {
            mid = l + (r - l)/2;
            if (strictlyLessThan(mid, mid + 1, nums)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};