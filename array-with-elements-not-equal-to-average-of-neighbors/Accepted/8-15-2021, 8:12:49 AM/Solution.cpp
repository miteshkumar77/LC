// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors

class Solution {
public:
    
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        vector<int> ans(n);    
        int l = n/2;
        int r = (n/2) + 1;
        int i = 0;
        while(i < n) {
            if (l >= 0) {
                ans[i++] = nums[l--];
            }
            if (r < n) {
                ans[i++] = nums[r++];
            }
        }
        return ans;
    }
};