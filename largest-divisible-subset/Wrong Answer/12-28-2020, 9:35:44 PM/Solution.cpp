// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> tmp{nums[i]};
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] % tmp.back() == 0) {
                    tmp.push_back(nums[j]);
                }
            }
            
            if (tmp.size() > ans.size()) {
                tmp.swap(ans);
            }
            tmp.clear();
        }
        
        return ans;
        
    }
};