// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int adj = -1;
        int min_ = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= min_) {
                min_ = nums[i];
            } else {
                adj = i;
            }
        }
        
        if (adj == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for (int i = 0; i < adj; ++i) {
            if (nums[i] < nums[adj]) {
                min_ = i;
            }
        }
        // [2, 3, 1]
        swap(nums[adj], nums[min_]);
        while(adj > min_ + 1 && nums[adj] < nums[adj-1])
            swap(nums[adj], nums[--adj]);
        
        while(adj + 1 < nums.size() && nums[adj] > nums[adj+1])
            swap(nums[adj], nums[++adj]);
    }
};