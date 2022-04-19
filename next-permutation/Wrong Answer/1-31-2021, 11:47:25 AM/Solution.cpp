// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        
        int n = nums.size();
        int bmax = n - 1;
        for (int j = n - 2; j >= 0; --j) {
            
            if (nums[bmax] < nums[j]) {
                bmax = j;
            }
            
            if (nums[j] < nums[bmax]) {
                int idxmax = bmax;
                for (int i = j + 1; i < n; ++i) {
                    if (nums[idxmax] > nums[i] && nums[i] > nums[j]) {
                        idxmax = i;
                    }
                }
                swap(nums[idxmax], nums[j]);
                reverse(nums.begin() + j + 1, nums.end());
                return;
            }
            
        }
        
        sort(nums.begin(), nums.end());
    }
};