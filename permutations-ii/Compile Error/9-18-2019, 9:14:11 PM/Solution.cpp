// https://leetcode.com/problems/permutations-ii

#include <unordered_map>
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> perms;
        unordered_map<const string, vector<int>> perms2;
        
        permute(nums,perms2, nums.size());
        
        for (unordered_map<const string, vector<int>>::const_iterator i = perms.begin(); i != perms.end(); i++) {
            perms.push_back(i -> second);
        }
        return perms;
        
    }
    
    void permute(vector<int>& nums, unordered_map<const string, vector<int>>& perms, int n) {
        if (n == 1) {
            
            string k = "";
            for (int i = 0; i < nums.size(); i++) {
                k += to_string(nums[i]);
            
            }
            perms.insert(make_pair(k, nums));
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