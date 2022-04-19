// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i - 1] == nums[i]) continue;
            
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                int res = nums[k] + nums[j] + nums[i];
                if (j != i + 1 && nums[j] == nums[i + 1]) {
                    ++j;
                } else if (k != n - 1 && nums[k] == nums[k + 1]) {
                    --k;
                } else if (res > 0) {
                    --k;
                } else if (res < 0) {
                    ++j;
                } else {
                    ans.push_back(vector<int>{nums[i], nums[j++], nums[k--]});
                }
            }
        }
        
        return ans;
    }
};