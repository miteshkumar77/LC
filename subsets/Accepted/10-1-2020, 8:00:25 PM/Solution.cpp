// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> box;
        function<void(int)> bt = [&](int i) -> void {
            if (i == nums.size()) {
                ans.push_back(box);
                return;
            }
            bt(i + 1);
            box.push_back(nums[i]);
            bt(i + 1);
            box.pop_back();
            
        };
        bt(0);
        return ans;
    }
};