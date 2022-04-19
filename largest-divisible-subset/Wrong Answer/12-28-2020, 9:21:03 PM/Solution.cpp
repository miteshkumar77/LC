// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        // a % b == 0
        // c % a == 0
        // c % b == 0
        
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> cand{nums[i]};
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0) {
                    cand.push_back(nums[j]);
                }
            }
            
            if (cand.size() > ans.size()) {
                ans.swap(cand);
            }
        }
        
        return ans;
        
    }
};