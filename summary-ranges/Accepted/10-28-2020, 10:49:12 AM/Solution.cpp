// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) {
            return ans;
        }
        int prev = nums[0];
        string tmp;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] != nums[i] - 1) {
                if (prev != nums[i - 1]) {
                    tmp = to_string(prev) + "->" + to_string(nums[i - 1]);
                } else {
                    tmp = to_string(prev);
                }
                prev = nums[i];
                ans.push_back(tmp);
            }
        }
        
        if (prev != nums.back()) {
            tmp = to_string(prev) + "->" + to_string(nums.back());
        } else {
            tmp = to_string(prev);
        }
        
        ans.push_back(tmp);
        return ans;
        
    }
};