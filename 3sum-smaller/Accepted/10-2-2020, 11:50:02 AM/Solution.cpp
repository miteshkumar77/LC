// https://leetcode.com/problems/3sum-smaller

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int k = n - 1;
            int j = i + 1;
            while(j < k) {
                if (nums[i] + nums[j] + nums[k] < target) {
                    ans += (k - j++);
                } else {
                    --k;
                }
            }
        }
        return ans;
    }
};