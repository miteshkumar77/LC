// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> box;
        function<void(int, bool)> bt = [&](int i, bool skip) -> void {
            if (!skip) {
                ans.push_back(box);
            }
            if (i == nums.size()) {
                return;
            }
            
            if (i == 0 || nums[i] != nums[i - 1]) {
                box.push_back(nums[i]);
                bt(i + 1, false);
                box.pop_back();
                bt(i + 1, true);
            } else {
                if (!skip) {
                    box.push_back(nums[i]);
                    bt(i + 1, false);
                    box.pop_back();
                    bt(i + 1, true);
                }
            }
            
        };
        
        bt(0, false);
        return ans;
    }
};