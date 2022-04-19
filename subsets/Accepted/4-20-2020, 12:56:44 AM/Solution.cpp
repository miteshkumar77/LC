// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = vector<vector<int>>(); 
        vector<int> subset = vector<int>(); 
        generate(subsets, nums, subset, 0); 
        subsets.push_back(vector<int>()); 
        return subsets; 
    }
    
    void generate(vector<vector<int>>& subsets, vector<int>& nums, vector<int>& subset, int k) {
        
        for (int i = k; i < nums.size(); ++i) {
            subset.push_back(nums[i]); 
            subsets.push_back(subset); 
            generate(subsets, nums, subset, i + 1); 
            subset.pop_back(); 
        }
    }
};