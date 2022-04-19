// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> perms;
        
        permute(nums,perms, nums.size());
        return perms;
        
    }
    
    void permute(vector<int>& nums, vector<vector<int>>& perms, int n) {
        if (n == 1) {
            perms.push_back(nums);
            return;
        }
        
        for (int i = 0; i < n - 1; i++) {
            permute(nums, perms, n - 1);
            
            if (n%2 == 0) {
                swap(nums[n - 1], nums[i]);
            } else {
                swap(nums[n - 1], nums[0]);
            }
        }
        
        permute(nums, perms, n - 1);
        return;
    }
};