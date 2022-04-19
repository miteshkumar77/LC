// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans; 
        
        function<void(int, int, int, int)> helper = [&] (int left, int right, int e1, int e2) -> void {
            int L = left; 
            int R = right; 
            
            while(L < R) {
                if (L != left && nums[L] == nums[L - 1]) {
                    ++L; 
                } else if (R != right && nums[R] == nums[R + 1]) {
                    --R; 
                } else if (nums[L] + nums[R] + e1 + e2 > target) {
                    --R; 
                } else if (nums[L] + nums[R] + e1 + e2 < target) {
                    ++L; 
                } else {
                    ans.push_back(vector<int>{nums[L++], nums[R--], e1, e2}); 
                }
            }
        };
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (j == i + 1 || nums[j] != nums[j - 1]) {
                        helper(j + 1, nums.size() - 1, nums[i], nums[j]); 
                    }
                }
            }
        }
        
        
        return ans; 
        
    }
};