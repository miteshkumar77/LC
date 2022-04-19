// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans; 
        list<int> tmp; 
        for (int i = 0; i <= nums.size(); ++i) {
            helper(nums, ans, tmp, 0, i); 
        }
        return ans; 
    }
    
    
    void helper(vector<int>& nums, vector<vector<int> >& ans, list<int>& tmp, int i, int k) {
        if (k == 0) {
            ans.push_back(vector<int>(tmp.begin(), tmp.end())); 
            return; 
        }
         
        for (int x = i; x < 1 + nums.size() - k; ++x) {
            tmp.push_back(nums[x]);
            helper(nums, ans, tmp, x + 1, k - 1); 
            tmp.pop_back(); 
        }
    }
};