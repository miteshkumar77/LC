// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(n);
        int l = 0;
        int r = n-1;    
        int x = 1;
        int i = 0;
        while(l < r) {
            if (x) {
                ans[i++] = nums[r--];
            } else {
                ans[i++] = nums[l++];
            }
            x ^= 1;
        }
        if (n % 2 == 1) {
            ans[i++] = nums[l];
        }
        return ans;
    }
};