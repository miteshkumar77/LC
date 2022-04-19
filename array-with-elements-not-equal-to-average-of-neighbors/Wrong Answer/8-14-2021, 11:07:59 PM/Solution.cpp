// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for (int i : nums) cout << i << ' ';
        for (int i = 2; i < nums.size(); ++i) {
            if ((nums[i] + nums[i-2]) % 2 == 0 && (nums[i] + nums[i-2])/2 == nums[i-1]) {
                swap(nums[i-1], nums[i-2]);
            }
        }
        return nums;
    }
};