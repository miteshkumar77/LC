// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int num_odd{0};
        int j = 0;
        int x = 0;
        int num_oddx{0};
        int n = nums.size();
        int ans{0};
        for (int i = 0; i < n; ++i) {
            num_odd += (nums[i] % 2);
            num_oddx += (nums[i] % 2);
            while(j <= i && num_odd > k) {
                num_odd -= (nums[j++] % 2);
            }
            while(x <= i && num_oddx >= k) {
                num_oddx -= (nums[x++] % 2);
            }
            if (num_odd == k) {
                ans += (x - j);
            }
        }
        return ans;
    }
};